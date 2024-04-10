`include "./include/config.v"

module CPU (
    input                   [ 0 : 0]            clk,
    input                   [ 0 : 0]            rst,

    input                   [ 0 : 0]            global_en,

/* ------------------------------ Memory (inst) ----------------------------- */
    output                  [31 : 0]            imem_raddr,
    input                   [31 : 0]            imem_rdata,

/* ------------------------------ Memory (data) ----------------------------- */
    input                   [31 : 0]            dmem_rdata, 
    output                  [ 0 : 0]            dmem_we,    
    output                  [31 : 0]            dmem_addr,  
    output                  [31 : 0]            dmem_wdata, 

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



    wire [31:0] cur_pc;
    PC my_pc (
        .clk    (clk        ),
        .rst    (rst        ),
        .en     (global_en  ),    // 当 global_en 为高电平时，PC 才会更新，CPU 才会执行指令。
        .npc    (cur_npc    ),

        .pc     (cur_pc     )
    );

    assign imem_raddr = cur_pc;

    wire [31: 0] inst = imem_rdata;

    wire [ 4: 0] alu_op;
    wire [ 3: 0] dmem_access;
    wire [31: 0] imm;
    wire [ 4: 0] rf_ra_k,rf_ra_j,rf_ra_d;
    wire [ 0: 0] rf_we,dmem_we;
    wire [ 1: 0] rf_wd_sel;
    wire [ 0: 0] alu_src0_sel,alu_src1_sel;
    wire [ 3: 0] br_type;
    DECODER my_decoder(
        .inst(inst),
        //输出端口
        .alu_op(alu_op),
        .dmem_access(dmem_access),
        .imm(imm),
        .rf_ra_k(rf_ra_k),
        .rf_ra_j(rf_ra_j),
        .rf_ra_d(rf_ra_d),
        .rf_we(rf_we),
        .dmem_we(dmem_we),
        .rf_wd_sel(rf_wd_sel),
        .alu_src0_sel(alu_src0_sel),
        .alu_src1_sel(alu_src1_sel),
        .br_type(br_type)
    );

    wire [31:0] rf_rd_k,rf_rd_j,rf_rd_d;
    RF my_rf(
        .clk       (clk),
        .rf_ra_k    (rf_ra_k),
        .rf_ra_j    (rf_ra_j),
        .rf_ra_d    (rf_ra_d),

        .rf_we     (rf_we),
        .rf_wd     (rf_wd),
        //输出端口
        .rf_rd_k    (rf_rd_k),
        .rf_rd_j    (rf_rd_j),
        .rf_rd_d    (rf_rd_d),

        .dbg_reg_ra(debug_reg_ra),
        .dbg_reg_rd(debug_reg_rd)
    );

    wire [31:0] alu_src0,alu_src1;
    MUX mux0(
        .src0(rf_rd_j),
        .src1(cur_pc),
        .sel(alu_src0_sel),

        .res(alu_src0)
    );
    MUX mux1(
        .src0(rf_rd_k),
        .src1(imm),
        .sel(alu_src1_sel),

        .res(alu_src1)
    );

    wire [31:0] alu_res;
    ALU my_alu(
        .alu_src0(alu_src0),
        .alu_src1(alu_src1),
        .alu_op(alu_op),

        .alu_res(alu_res)
    );
    
    wire [0:0] npc_sel;
    BRANCH my_branch(
        .br_type(br_type),
        .br_src0(rf_rd_j),
        .br_src1(rf_rd_d),

        .npc_sel(npc_sel)
    );

    wire [31:0] addr = alu_res;
    assign dmem_addr = addr;
    wire [31:0] rd_out;
    SLU my_slu(
        .addr(addr),
        .dmem_access(dmem_access),
        .rd_in(dmem_rdata),
        .wd_in(rf_rd_d),

        .rd_out(rd_out),
        .wd_out(dmem_wdata)
    );

    wire [31:0] pc_add4 = cur_pc + 32'd4;

    wire [31:0] cur_npc;
    NPCMUX my_npc(
        .pc_add4(pc_add4),
        .pc_offset(alu_res),
        .npc_sel(npc_sel),

        .npc(cur_npc)
    );

    wire [31:0] rf_wd;
    MUX1 my_rf_wd(
        .src0(pc_add4),
        .src1(alu_res),
        .src2(rd_out),
        .src3(32'b0),
        .sel(rf_wd_sel),

        .res(rf_wd)
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
            commit_pc_reg       <= cur_pc;       
            commit_inst_reg     <= inst;       
            commit_halt_reg     <= (inst == HALT_INST);       
            commit_reg_we_reg   <= rf_we;       
            commit_reg_wa_reg   <= rf_ra_d;       
            commit_reg_wd_reg   <= rf_wd;       
            commit_dmem_we_reg  <= dmem_we;
            commit_dmem_wa_reg  <= dmem_addr;
            commit_dmem_wd_reg  <= dmem_wdata;
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