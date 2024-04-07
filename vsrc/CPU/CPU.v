`include "./include/config.v"

`define HALT_INST           32'h8000_0000

`define ADD                 5'B00000    
`define SUB                 5'B00010   
`define SLT                 5'B00100
`define SLTU                5'B00101
`define AND                 5'B01001
`define OR                  5'B01010
`define XOR                 5'B01011
`define SLL                 5'B01110   
`define SRL                 5'B01111    
`define SRA                 5'B10000  
`define SRC0                5'B10001
`define SRC1                5'B10010

module CPU (
    input                   [ 0 : 0]            clk,
    input                   [ 0 : 0]            rst,

    input                   [ 0 : 0]            global_en,

/* ------------------------------ Memory (inst) ----------------------------- */
    output                  [31 : 0]            imem_raddr,
    input                   [31 : 0]            imem_rdata,

/* ------------------------------ Memory (data) ----------------------------- */
    input                   [31 : 0]            dmem_rdata, // Unused
    output                  [ 0 : 0]            dmem_we,    // Unused
    output                  [31 : 0]            dmem_addr,  // Unused
    output                  [31 : 0]            dmem_wdata, // Unused

/* ---------------------------------- Debug --------------------------------- */
    output                  [ 0 : 0]            commit,
    output                  [31 : 0]            commit_pc,
    output                  [31 : 0]            commit_inst,
    output                  [ 0 : 0]            commit_halt,
    output                  [ 0 : 0]            commit_reg_we,
    output                  [ 4 : 0]            commit_reg_wa,
    output                  [31 : 0]            commit_reg_wd,
    output                  [ 0 : 0]            commit_dmem_we,
    output                  [31 : 0]            commit_dmem_wa,
    output                  [31 : 0]            commit_dmem_wd,

    input                   [ 4 : 0]            debug_reg_ra,
    output                  [31 : 0]            debug_reg_rd
);


// TODO

/* -------------------------------------------------------------------------- */
/*                                    Commit                                  */
/* -------------------------------------------------------------------------- */

    wire [ 0 : 0] commit_if     ;
    assign commit_if = 1'H1;

    reg  [ 0 : 0]   commit_reg          ;
    reg  [31 : 0]   commit_pc_reg       ;
    reg  [31 : 0]   commit_inst_reg     ;
    reg  [ 0 : 0]   commit_halt_reg     ;
    reg  [ 0 : 0]   commit_reg_we_reg   ;
    reg  [ 4 : 0]   commit_reg_wa_reg   ;
    reg  [31 : 0]   commit_reg_wd_reg   ;
    reg  [ 0 : 0]   commit_dmem_we_reg  ;
    reg  [31 : 0]   commit_dmem_wa_reg  ;
    reg  [31 : 0]   commit_dmem_wd_reg  ;

    wire [31:0] cur_pc,cur_npc;
    PC my_pc (
        .clk    (clk        ),
        .rst    (rst        ),
        .en     (global_en  ),    // 当 global_en 为高电平时，PC 才会更新，CPU 才会执行指令。
        .npc    (cur_npc    ),
        .pc     (cur_pc     )
    );
    assign imem_raddr = cur_pc;
    ALU pc_alu(
        .alu_src0(cur_pc),
        .alu_src1(32'd4),
        .alu_op(`ADD),
        .alu_res(cur_npc)
    );
    wire [4:0]  alu_op;
    wire [31:0] imm;
    wire [4:0] rf_ra0,rf_ra1,rf_wa;
    wire [0:0] rf_we;
    wire [0:0] alu_src0_sel,alu_src1_sel;
    DECODER my_decoder(
        .inst(imem_rdata),

        .alu_op(alu_op),
        .imm(imm),
        .rf_ra0(rf_ra0),
        .rf_ra1(rf_ra1),
        .rf_wa(rf_wa),
        .rf_we(rf_we),
        .alu_src0_sel(alu_src0_sel),
        .alu_src1_sel(alu_src1_sel)
    );
    wire [31:0] alu_res;

    wire [31:0] rf_rd0,rf_rd1;
    RF my_rf(
            .clk       (clk),
            .rf_ra0    (rf_ra0),
            .rf_ra1    (rf_ra1),
            .rf_wa     (rf_wa),
            .rf_we     (rf_we),
            .rf_wd     (alu_res),

            .rf_rd0    (rf_rd0),
            .rf_rd1    (rf_rd1),

            .dbg_reg_ra(debug_reg_ra),
            .dbg_reg_rd(debug_reg_rd)
    );
    wire [31:0] alu_src0,alu_src1;
    MUX mux0(
        .src0(rf_rd0),
        .src1(cur_pc),
        .sel(alu_src0_sel),
        .res(alu_src0)
    );
    MUX mux1(
        .src0(rf_rd1),
        .src1(imm),
        .sel(alu_src1_sel),
        .res(alu_src1)
    );
    ALU my_alu(
        .alu_src0(alu_src0),
        .alu_src1(alu_src1),
        .alu_op(alu_op),
        .alu_res(alu_res)
    );

    always @(posedge clk) begin
        if (rst) begin
            commit_reg          <= 1'H0;
            commit_pc_reg       <= 32'H0;
            commit_inst_reg     <= 32'H0;
            commit_halt_reg     <= 1'H0;
            commit_reg_we_reg   <= 1'H0;
            commit_reg_wa_reg   <= 5'H0;
            commit_reg_wd_reg   <= 32'H0;
            commit_dmem_we_reg  <= 1'H0;
            commit_dmem_wa_reg  <= 32'H0;
            commit_dmem_wd_reg  <= 32'H0;
        end
        else if (global_en) begin
            commit_reg          <= commit_if;
            commit_pc_reg       <= cur_pc;       // TODO
            commit_inst_reg     <= imem_rdata;       // TODO
            commit_halt_reg     <= (imem_rdata == `HALT_INST);       // TODO
            commit_reg_we_reg   <= rf_we;       // TODO
            commit_reg_wa_reg   <= rf_wa;       // TODO
            commit_reg_wd_reg   <= alu_res;       // TODO
            commit_dmem_we_reg  <= 0;
            commit_dmem_wa_reg  <= 0;
            commit_dmem_wd_reg  <= 0;
        end
    end

    assign commit               = commit_reg;
    assign commit_pc            = commit_pc_reg;
    assign commit_inst          = commit_inst_reg;
    assign commit_halt          = commit_halt_reg;
    assign commit_reg_we        = commit_reg_we_reg;
    assign commit_reg_wa        = commit_reg_wa_reg;
    assign commit_reg_wd        = commit_reg_wd_reg;
    assign commit_dmem_we       = commit_dmem_we_reg;
    assign commit_dmem_wa       = commit_dmem_wa_reg;
    assign commit_dmem_wd       = commit_dmem_wd_reg;



endmodule