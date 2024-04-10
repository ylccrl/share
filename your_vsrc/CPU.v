
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/07 23:56:14
// Design Name: 
// Module Name: CPU
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


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

wire [31 : 0] cur_npc, cur_pc, imm, rf_rd0, rf_rd1, rf_wd, alu_src0, alu_src1;
wire [ 0 : 0] rf_we, alu_src0_sel, alu_src1_sel;
wire [ 4 : 0] alu_op, rf_ra0, rf_ra1, rf_wa;

wire [31 : 0] cur_npc_t, cur_pc_t, imm_t, rf_rd0_t, rf_rd1_t, rf_wd_t, alu_src0_t, alu_src1_t;
wire [ 4 : 0] alu_op_t, rf_ra0_t, rf_ra1_t, rf_wa_t;
wire [ 0 : 0] rf_we_t, alu_src0_sel_t, alu_src1_sel_t;

PC my_pc (
    .clk    (clk        ),
    .rst    (rst        ),
    .en     (global_en  ),    // 当 global_en 为高电平时，PC 才会更新，CPU 才会执行指令。
    .npc    (cur_npc_t  ),

    .pc     (cur_pc     )
);

ADD4 my_add4(
    .pc         (cur_pc_t   ),
    .npc        (cur_npc    )
);

DECODE my_decode(
    .inst         (imem_rdata   ),

    .alu_op       (alu_op       ),
    .imm          (imm          ),
    .rf_ra0       (rf_ra0       ),
    .rf_ra1       (rf_ra1       ),
    .rf_we        (rf_we        ),
    .rf_wa        (rf_wa        ),
    .alu_src0_sel (alu_src0_sel ),
    .alu_src1_sel (alu_src1_sel )
);

assign  cur_pc_t = cur_pc;
assign  cur_npc_t = cur_npc;
assign  alu_op_t = alu_op;
assign  imm_t = imm;
assign  rf_ra0_t = rf_ra0;
assign  rf_ra1_t = rf_ra1;
assign  rf_rd0_t = rf_rd0;
assign  rf_rd1_t = rf_rd1;
assign  rf_we_t = rf_we;
assign  rf_wa_t = rf_wa;
assign  rf_wd_t = rf_wd;
assign  alu_src0_t = alu_src0;
assign  alu_src1_t = alu_src1;
assign  alu_src0_sel_t = alu_src0_sel;
assign  alu_src1_sel_t = alu_src1_sel;

REG_FILE my_regfile(
    .clk            (clk            ),
    .rf_ra0         (rf_ra0_t       ),
    .rf_ra1         (rf_ra1_t       ),
    .dbg_reg_ra     (debug_reg_ra   ),
    .rf_wa          (rf_wa_t        ),
    .rf_we          (rf_we_t        ),
    .rf_wd          (rf_wd_t        ),

    .rf_rd0         (rf_rd0         ),
    .rf_rd1         (rf_rd1         ),
    .dbg_reg_rd     (debug_reg_rd   )
);

MUX1 my_mux0(
    .src0           (rf_rd0_t       ),
    .src1           (cur_pc_t       ),
    .sel            (alu_src0_sel_t ),

    .res            (alu_src0       )
);

MUX1 my_mux1(
    .src0           (rf_rd1_t       ),
    .src1           (imm_t          ),
    .sel            (alu_src1_sel_t ),

    .res            (alu_src1       )
);

ALU my_alu(
    .alu_src0       (alu_src0_t     ),
    .alu_src1       (alu_src1_t     ),
    .alu_op         (alu_op_t       ),

    .alu_res        (rf_wd          )
);

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
        // !!!! 请注意根据自己的具体实现替换 <= 右侧的信号 !!!!
        commit_reg          <= 1'H1;                        // 不需要改动
        commit_pc_reg       <= cur_pc;                      // 需要为当前的 PC
        commit_inst_reg     <= imem_rdata;                  // 需要为当前的指令
        commit_halt_reg     <= (imem_rdata == 32'h8000_0000);                   // 注意！请根据指令集设置 HALT_INST！
        commit_reg_we_reg   <= rf_we;                       // 需要为当前的寄存器堆写使能
        commit_reg_wa_reg   <= rf_wa;                       // 需要为当前的寄存器堆写地址
        commit_reg_wd_reg   <= rf_wd;                       // 需要为当前的寄存器堆写数据
        commit_dmem_we_reg  <= 0;                           // 不需要改动
        commit_dmem_wa_reg  <= 0;                           // 不需要改动
        commit_dmem_wd_reg  <= 0;                           // 不需要改动
    end
end

assign imem_raddr           = cur_pc;
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

