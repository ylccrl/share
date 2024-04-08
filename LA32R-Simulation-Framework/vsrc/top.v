`include "configs.vh"

import "DPI-C" function void expose_configs(int _instMemStart, int _instMemDepth, string _instMemFile, int _dataMemStart, int _dataMemDepth, string DataMemFile, byte _core, bit _uartIO);

module
    Top (
        // basic ports
        input                   [ 0 : 0]                    clk,
        input                   [ 0 : 0]                    rst,

        output                  [ 0 : 0]                    uart_we,
        output                  [ 7 : 0]                    uart_wdata,
        input                   [ 0 : 0]                    uart_ready,
        input                   [ 7 : 0]                    uart_rdata,
        output                  [ 0 : 0]                    uart_consumed,

        // ports for simulation and difftest
        output                  [ 0 : 0]                    commit,
        output                  [ 0 : 0]                    commit_halt,

        // for difftest
        output                  [31 : 0]                    commit_pc, 
        output                  [31 : 0]                    commit_inst,

        // compare commit
        output                  [ 0 : 0]                    commit_reg_we,
        output                  [ 4 : 0]                    commit_reg_wa,
        output                  [31 : 0]                    commit_reg_wd,
        output                  [ 0 : 0]                    commit_dmem_we,
        output                  [`DATA_MEM_DEPTH - 1 : 0]   commit_dmem_wa,
        output                  [31 : 0]                    commit_dmem_wd,

        // compare full status
        input                   [ 4 : 0]                    debug_reg_ra,
        output                  [31 : 0]                    debug_reg_rd
    );

    initial begin
        expose_configs(`INST_MEM_START, `INST_MEM_DEPTH, `INST_MEM_FILE, `DATA_MEM_START, `DATA_MEM_DEPTH, `DATA_MEM_FILE, `CORE_TYPE, `UART_IO);
    end

    wire [31 : 0] pc;
    wire [31 : 0] inst;

    wire [31 : 0] dmem_wdata;
    wire [31 : 0] dmem_rdata;
    wire [ 0 : 0] dmem_we;

    wire [31 : 0] cpu_dmem_addr;
    wire [31 : 0] cpu_dmem_rdata;
    wire [31 : 0] cpu_dmem_wdata;
    wire [ 0 : 0] cpu_dmem_we;

    wire [31 : 0] cpu_commit_dmem_wa;

    assign commit_dmem_wa = cpu_commit_dmem_wa[`DATA_MEM_DEPTH + 1 : 2];

    CPU cpu(
        .clk                    (clk),
        .rst                    (rst),
        .global_en              (1'B1),

        .imem_raddr             (pc),
        .imem_rdata             (inst),

        .dmem_addr              (cpu_dmem_addr),
        .dmem_rdata             (cpu_dmem_rdata),
        .dmem_wdata             (cpu_dmem_wdata),
        .dmem_we                (cpu_dmem_we),

        .commit                 (commit),
        .commit_pc              (commit_pc),
        .commit_inst            (commit_inst),
        .commit_halt            (commit_halt),
        .commit_reg_we          (commit_reg_we),
        .commit_reg_wa          (commit_reg_wa),
        .commit_reg_wd          (commit_reg_wd),
        .commit_dmem_we         (commit_dmem_we),
        .commit_dmem_wa         (cpu_commit_dmem_wa),
        .commit_dmem_wd         (commit_dmem_wd),

        .debug_reg_ra           (debug_reg_ra),
        .debug_reg_rd           (debug_reg_rd)
    );

    InstMem inst_mem(
        .a                      (pc[`INST_MEM_DEPTH + 1 : 2]),
        .spo                    (inst)
    );

    DataMem data_mem(
        .a                      (cpu_dmem_addr[`DATA_MEM_DEPTH + 1 : 2]),
        .d                      (dmem_wdata),
        .clk                    (clk),
        .we                     (dmem_we),
        .spo                    (dmem_rdata)
    );

    // MMIO
    // 32'HA00003F0         uart_wdata          write_only
    // 32'HA00003F4         uart_rdata          read_only
    // 32'HA00003F8         uart_ready          read_only
    // 32'HA00003FC         uart_consumed       write_only

    assign dmem_wdata = cpu_dmem_wdata;
    assign uart_wdata = cpu_dmem_wdata[7 : 0];

    assign uart_we = cpu_dmem_addr == 32'HA00003F0 ? cpu_dmem_we : 0;
    assign dmem_we = (cpu_dmem_addr & 32'HFFFFFFF0) != 32'HA00003F0 ? cpu_dmem_we : 0;
    assign uart_consumed = cpu_dmem_addr == 32'HA00003FC ? cpu_dmem_we : 0;

    assign cpu_dmem_rdata = cpu_dmem_addr == 32'HA00003F4 ? {24'H0, uart_rdata} : 
                            cpu_dmem_addr == 32'HA00003F8 ? {31'H0, uart_ready} :
                                                            dmem_rdata;

endmodule