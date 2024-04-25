`define HALT_INST           32'H80000000

`define ALU_OP_INIT         5'B01001//ADD
`define DMEM_ACCESS_INIT    4'B1010
`define IMM_INIT            32'B0
`define RF_RA0_INIT         5'b0
`define RF_RA1_INIT         5'b0
`define RF_WA_INIT          5'B0
`define RF_WE_INIT          1'B1
`define RF_WD_SEL_INIT      2'B01
`define DMEM_WE_INIT        1'B0
`define ALU_SRC0_SEL_INIT   1'B0
`define ALU_SRC1_SEL_INIT   1'B1
`define BR_TYPE_INIT        6'B0
`define RF_RD0_INIT         32'B0
`define RF_RD1_INIT         32'B0
`define ALU_RES_INIT        32'B0
`define RD_OUT_INIT         32'B0
`define DMEM_WDATA_INIT     32'B0

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

    input                   [ 4 : 0]            debug_reg_ra,   // TODO
    output                  [31 : 0]            debug_reg_rd    // TODO
);
wire [0:0] flush;

/* IF */
    wire [ 0: 0] commit_if = 1'H1;
    wire [31: 0] pc_if,inst_if,pcadd4_if;
    wire [31: 0] npc_ex;

    PC my_pc(
            .clk    (clk        ),
            .rst    (rst        ),
            .en     (global_en  ),    // 当 global_en 为高电平时，PC 才会更新，CPU 才会执行指令。
            .npc    (npc_ex     ),
            .stall  (1'b0       ),
            .flush  (1'b0       ),
            .pc     (pc_if      )
    );

    assign imem_raddr = pc_if;
    assign pcadd4_if = pc_if + 4;
    assign inst_if = imem_rdata;

wire [ 0: 0] commit_id;
wire [31: 0] inst_id,pc_id,pcadd4_id;

wire [ 4: 0] alu_op_if = `ALU_OP_INIT;
wire [ 3: 0] dmem_access_if = `DMEM_ACCESS_INIT;
wire [31: 0] imm_if = `IMM_INIT;
wire [ 4: 0] rf_ra0_if = `RF_RA0_INIT,rf_ra1_if = `RF_RA1_INIT;
wire [ 4: 0] rf_wa_if = `RF_WA_INIT;
wire [ 0: 0] rf_we_if = `RF_WE_INIT;
wire [ 1: 0] rf_wd_sel_if = `RF_WD_SEL_INIT;
wire [ 0: 0] dmem_we_if = `DMEM_WE_INIT;
wire [ 0: 0] alu_src0_sel_if = `ALU_SRC0_SEL_INIT,alu_src1_sel_if = `ALU_SRC1_SEL_INIT;
wire [ 5: 0] br_type_if = `BR_TYPE_INIT;
wire [31: 0] rf_rd0_if = `RF_RD0_INIT,rf_rd1_if = `RF_RD1_INIT;
wire [31: 0] alu_res_if = `ALU_RES_INIT;
wire [31: 0] rd_out_if = `RD_OUT_INIT;
wire [31: 0] dmem_wdata_if = `DMEM_WDATA_INIT;
SEG_REG IF_ID(
    .clk(clk),
    .rst(rst),
    .en(global_en),
    .flush(flush),
    .stall(1'b0),
    /* COMMIT */
    .commit_in(commit_if),
    .commit_out(commit_id),
    /* IF */
    .pc_in(pc_if),
    .inst_in(inst_if),
    .pcadd4_in(pcadd4_if),
    
    .pc_out(pc_id),
    .inst_out(inst_id),
    .pcadd4_out(pcadd4_id),
    /* ID */
    .alu_op_in(alu_op_if),
    .dmem_access_in(dmem_access_if),
    .imm_in(imm_if),
    .rf_ra0_in(rf_ra0_if),
    .rf_ra1_in(rf_ra1_if),
    .rf_wa_in(rf_wa_if),
    .rf_we_in(rf_we_if),
    .rf_wd_sel_in(rf_wd_sel_if),
    .dmem_we_in(dmem_we_if),
    .alu_src0_sel_in(alu_src0_sel_if),
    .alu_src1_sel_in(alu_src1_sel_if),
    .br_type_in(br_type_if),

    .alu_op_out(),
    .dmem_access_out(),
    .imm_out(),
    .rf_ra0_out(),
    .rf_ra1_out(),
    .rf_wa_out(),
    .rf_we_out(),
    .rf_wd_sel_out(),
    .dmem_we_out(),
    .alu_src0_sel_out(),
    .alu_src1_sel_out(),
    .br_type_out(),

    .rf_rd0_in(rf_rd0_if),
    .rf_rd1_in(rf_rd1_if),

    .rf_rd0_out(),
    .rf_rd1_out(),
    /* EX */
    .alu_res_in(alu_res_if),
    .alu_res_out(),
    /* MEM */
    .rd_out_in(rd_out_if),
    .rd_out_out(),
    .dmem_wdata_in(dmem_wdata_if),
    .dmem_wdata_out()
    /* WB */
);

/* ID */
    wire [ 4: 0] alu_op_id;
    wire [ 3: 0] dmem_access_id;
    wire [31: 0] imm_id;
    wire [ 4: 0] rf_ra0_id,rf_ra1_id,rf_wa_id;
    wire [ 0: 0] rf_we_id;
    wire [ 1: 0] rf_wd_sel_id;
    wire [ 0: 0] dmem_we_id;
    wire [ 0: 0] alu_src0_sel_id,alu_src1_sel_id;
    wire [ 5: 0] br_type_id;
    DECODER my_decoder(
        .inst(inst_id),
        //输出端口
        .alu_op(alu_op_id),
        .dmem_access(dmem_access_id),
        .imm(imm_id),
        .rf_ra0(rf_ra0_id),
        .rf_ra1(rf_ra1_id),
        .rf_wa(rf_wa_id),
        .rf_we(rf_we_id),
        .rf_wd_sel(rf_wd_sel_id),
        .dmem_we(dmem_we_id),
        .alu_src0_sel(alu_src0_sel_id),
        .alu_src1_sel(alu_src1_sel_id),
        .br_type(br_type_id)
    );

    wire [31: 0] rf_rd0_id,rf_rd1_id;
    wire [ 4: 0] rf_wa_wb;
    wire [ 0: 0] rf_we_wb;
    wire [31: 0] rf_wd_wb;
    REG_FILE my_rf(
        .clk       (clk),
        .rf_ra0    (rf_ra0_id),
        .rf_ra1    (rf_ra1_id),

        .rf_wa     (rf_wa_wb),
        .rf_we     (rf_we_wb),
        .rf_wd     (rf_wd_wb),
        //输出端口
        .rf_rd0    (rf_rd0_id),
        .rf_rd1    (rf_rd1_id),

        .dbg_reg_ra(debug_reg_ra),
        .dbg_reg_rd(debug_reg_rd)
    );


wire [ 0: 0] commit_ex;
wire [31: 0] pc_ex,inst_ex,pcadd4_ex;
wire [ 4: 0] alu_op_ex;
wire [ 3: 0] dmem_access_ex;
wire [31: 0] imm_ex;
wire [ 4: 0] rf_ra0_ex,rf_ra1_ex,rf_wa_ex;
wire [ 0: 0] rf_we_ex;
wire [ 1: 0] rf_wd_sel_ex;
wire [ 0: 0] dmem_we_ex;
wire [ 0: 0] alu_src0_sel_ex,alu_src1_sel_ex;
wire [ 5: 0] br_type_ex;
wire [31: 0] rf_rd0_ex,rf_rd1_ex;

wire [31: 0] alu_res_id = `ALU_RES_INIT;
wire [31: 0] rd_out_id = `RD_OUT_INIT;
wire [31: 0] dmem_wdata_id = `DMEM_WDATA_INIT;
SEG_REG ID_EX(
    .clk(clk),
    .rst(rst),
    .en(global_en),
    .flush(flush),
    .stall(1'b0),
    /* COMMIT */
    .commit_in(commit_id),
    .commit_out(commit_ex),
    /* IF */
    .pc_in(pc_id),
    .inst_in(inst_id),
    .pcadd4_in(pcadd4_id),
    
    .pc_out(pc_ex),
    .inst_out(inst_ex),
    .pcadd4_out(pcadd4_ex),
    /* ID */
    .alu_op_in(alu_op_id),
    .dmem_access_in(dmem_access_id),
    .imm_in(imm_id),
    .rf_ra0_in(rf_ra0_id),
    .rf_ra1_in(rf_ra1_id),
    .rf_wa_in(rf_wa_id),
    .rf_we_in(rf_we_id),
    .rf_wd_sel_in(rf_wd_sel_id),
    .dmem_we_in(dmem_we_id),
    .alu_src0_sel_in(alu_src0_sel_id),
    .alu_src1_sel_in(alu_src1_sel_id),
    .br_type_in(br_type_id),

    .alu_op_out(alu_op_ex),
    .dmem_access_out(dmem_access_ex),
    .imm_out(imm_ex),
    .rf_ra0_out(rf_ra0_ex),
    .rf_ra1_out(rf_ra1_ex),
    .rf_wa_out(rf_wa_ex),
    .rf_we_out(rf_we_ex),
    .rf_wd_sel_out(rf_wd_sel_ex),
    .dmem_we_out(dmem_we_ex),
    .alu_src0_sel_out(alu_src0_sel_ex),
    .alu_src1_sel_out(alu_src1_sel_ex),
    .br_type_out(br_type_ex),

    .rf_rd0_in(rf_rd0_id),
    .rf_rd1_in(rf_rd1_id),

    .rf_rd0_out(rf_rd0_ex),
    .rf_rd1_out(rf_rd1_ex),
    /* EX */
    .alu_res_in(alu_res_id),
    .alu_res_out(),
    /* MEM */
    .rd_out_in(rd_out_id),
    .rd_out_out(),
    .dmem_wdata_in(dmem_wdata_id),
    .dmem_wdata_out()
    /* WB */
);

/* EX */
    wire [31: 0] alu_src0_ex,alu_src1_ex;
    MUX2_1 mux0(
        .src0(rf_rd0_ex),
        .src1(pc_ex),
        .sel(alu_src0_sel_ex),

        .res(alu_src0_ex)
    );
    MUX2_1 mux1(
        .src0(rf_rd1_ex),
        .src1(imm_ex),
        .sel(alu_src1_sel_ex),

        .res(alu_src1_ex)
    );
    wire [31: 0] alu_res_ex;
    ALU my_alu(
        .alu_src0(alu_src0_ex),
        .alu_src1(alu_src1_ex),
        .alu_op(alu_op_ex),

        .alu_res(alu_res_ex)
    );  
    wire [ 0: 0] npc_sel_ex;
    BRANCH my_branch(
        .br_type(br_type_ex),
        .br_src0(rf_rd0_ex),
        .br_src1(rf_rd1_ex),

        .npc_sel(npc_sel_ex)
    ); 

    MUX2_1 my_npc(
        .src0(pcadd4_if),
        .src1(alu_res_ex),
        .sel(npc_sel_ex),

        .res(npc_ex)
    );
    assign flush = (npc_sel_ex==1'b1)?1'b1:1'b0;

wire [ 0: 0] commit_mem;
wire [31: 0] pc_mem,inst_mem,pcadd4_mem;
wire [ 4: 0] alu_op_mem;
wire [ 3: 0] dmem_access_mem;
wire [31: 0] imm_mem;
wire [ 4: 0] rf_ra0_mem,rf_ra1_mem,rf_wa_mem;
wire [ 0: 0] rf_we_mem;
wire [ 1: 0] rf_wd_sel_mem;
wire [ 0: 0] dmem_we_mem;
wire [ 0: 0] alu_src0_sel_mem,alu_src1_sel_mem;
wire [ 5: 0] br_type_mem;
wire [31: 0] rf_rd0_mem,rf_rd1_mem;
wire [31: 0] alu_res_mem;

wire [31: 0] rd_out_ex = `RD_OUT_INIT;
wire [31: 0] dmem_wdata_ex = `DMEM_WDATA_INIT;
SEG_REG EX_MEM(
    .clk(clk),
    .rst(rst),
    .en(global_en),
    .flush(1'b0),
    .stall(1'b0),
    /* COMMIT */
    .commit_in(commit_ex),
    .commit_out(commit_mem),
    /* IF */
    .pc_in(pc_ex),
    .inst_in(inst_ex),
    .pcadd4_in(pcadd4_ex),
    
    .pc_out(pc_mem),
    .inst_out(inst_mem),
    .pcadd4_out(pcadd4_mem),
    /* ID */
    .alu_op_in(alu_op_ex),
    .dmem_access_in(dmem_access_ex),
    .imm_in(imm_ex),
    .rf_ra0_in(rf_ra0_ex),
    .rf_ra1_in(rf_ra1_ex),
    .rf_wa_in(rf_wa_ex),
    .rf_we_in(rf_we_ex),
    .rf_wd_sel_in(rf_wd_sel_ex),
    .dmem_we_in(dmem_we_ex),
    .alu_src0_sel_in(alu_src0_sel_ex),
    .alu_src1_sel_in(alu_src1_sel_ex),
    .br_type_in(br_type_ex),

    .alu_op_out(alu_op_mem),
    .dmem_access_out(dmem_access_mem),
    .imm_out(imm_mem),
    .rf_ra0_out(rf_ra0_mem),
    .rf_ra1_out(rf_ra1_mem),
    .rf_wa_out(rf_wa_mem),
    .rf_we_out(rf_we_mem),
    .rf_wd_sel_out(rf_wd_sel_mem),
    .dmem_we_out(dmem_we_mem),
    .alu_src0_sel_out(alu_src0_sel_mem),
    .alu_src1_sel_out(alu_src1_sel_mem),
    .br_type_out(br_type_mem),

    .rf_rd0_in(rf_rd0_ex),
    .rf_rd1_in(rf_rd1_ex),

    .rf_rd0_out(rf_rd0_mem),
    .rf_rd1_out(rf_rd1_mem),
    /* EX */
    .alu_res_in(alu_res_ex),
    .alu_res_out(alu_res_mem),
    /* MEM */
    .rd_out_in(rd_out_ex),
    .rd_out_out(),
    .dmem_wdata_in(dmem_wdata_ex),
    .dmem_wdata_out()
    /* WB */
);

/* MEM */
    wire [31: 0] rd_out_mem;
    wire [31: 0] dmem_wdata_mem;

    assign dmem_addr = alu_res_mem;

    SL_UNIT my_slu(
        .addr(alu_res_mem),
        .dmem_access(dmem_access_mem),
        .rd_in(dmem_rdata),
        .wd_in(rf_rd1_mem),

        .rd_out(rd_out_mem),
        .wd_out(dmem_wdata_mem)
    );
    assign dmem_we = dmem_we_mem;
    assign dmem_wdata = dmem_wdata_mem;

wire [ 0: 0] commit_wb;
wire [31: 0] pc_wb,inst_wb,pcadd4_wb;
wire [ 4: 0] alu_op_wb;
wire [ 3: 0] dmem_access_wb;
wire [31: 0] imm_wb;
wire [ 4: 0] rf_ra0_wb,rf_ra1_wb;
wire [ 1: 0] rf_wd_sel_wb;
wire [ 0: 0] dmem_we_wb;
wire [ 0: 0] alu_src0_sel_wb,alu_src1_sel_wb;
wire [ 5: 0] br_type_wb;
wire [31: 0] rf_rd0_wb,rf_rd1_wb;
wire [31: 0] alu_res_wb;
wire [31: 0] rd_out_wb;
wire [31: 0] dmem_wdata_wb;

SEG_REG MEM_WB(
    .clk(clk),
    .rst(rst),
    .en(global_en),
    .flush(1'b0),
    .stall(1'b0),
    /* COMMIT */
    .commit_in(commit_mem),
    .commit_out(commit_wb),
    /* IF */
    .pc_in(pc_mem),
    .inst_in(inst_mem),
    .pcadd4_in(pcadd4_mem),
    
    .pc_out(pc_wb),
    .inst_out(inst_wb),
    .pcadd4_out(pcadd4_wb),
    /* ID */
    .alu_op_in(alu_op_mem),
    .dmem_access_in(dmem_access_mem),
    .imm_in(imm_mem),
    .rf_ra0_in(rf_ra0_mem),
    .rf_ra1_in(rf_ra1_mem),
    .rf_wa_in(rf_wa_mem),
    .rf_we_in(rf_we_mem),
    .rf_wd_sel_in(rf_wd_sel_mem),
    .dmem_we_in(dmem_we_mem),
    .alu_src0_sel_in(alu_src0_sel_mem),
    .alu_src1_sel_in(alu_src1_sel_mem),
    .br_type_in(br_type_mem),

    .alu_op_out(alu_op_wb),
    .dmem_access_out(dmem_access_wb),
    .imm_out(imm_wb),
    .rf_ra0_out(rf_ra0_wb),
    .rf_ra1_out(rf_ra1_wb),
    .rf_wa_out(rf_wa_wb),
    .rf_we_out(rf_we_wb),
    .rf_wd_sel_out(rf_wd_sel_wb),
    .dmem_we_out(dmem_we_wb),
    .alu_src0_sel_out(alu_src0_sel_wb),
    .alu_src1_sel_out(alu_src1_sel_wb),
    .br_type_out(br_type_wb),

    .rf_rd0_in(rf_rd0_mem),
    .rf_rd1_in(rf_rd1_mem),

    .rf_rd0_out(rf_rd0_wb),
    .rf_rd1_out(rf_rd1_wb),
    /* EX */
    .alu_res_in(alu_res_mem),
    .alu_res_out(alu_res_wb),
    /* MEM */
    .rd_out_in(rd_out_mem),
    .rd_out_out(rd_out_wb),
    .dmem_wdata_in(dmem_wdata_mem),
    .dmem_wdata_out(dmem_wdata_wb)
    /* WB */
);

/* WB */
    MUX4_1 my_rf_wd(
        .src0(pcadd4_wb),
        .src1(alu_res_wb),
        .src2(rd_out_wb),
        .src3(32'b0),
        .sel(rf_wd_sel_wb),
        //
        .res(rf_wd_wb)
    );
/* */
    wire [ 31 : 0] rf_wd_mem = alu_res_mem;
    FOWARDING my_foward(
        .rf_we_mem(rf_we_mem),
        .rf_we_wb(rf_we_wb),
        .rf_wa_mem(rf_wa_mem),
        .rf_wa_wb(rf_wa_wb),
        .rf_wd_mem(rf_wd_mem),
        .rf_wd_wb(rf_wd_wb),
        .rf_ra0_ex(rf_ra0_ex),
        .rf_ra1_ex(rf_ra1_ex),

        .rf_rd0_fe(rf_rd0_fe),
        .rf_rd1_fe(rf_rd1_fe),
        .rf_rd0_fd(rf_rd0_fd),
        .rf_rd1_fd(rf_rd1_fd)
    );

    // Commit
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

    // Commit
    always @(posedge clk) begin
        if (rst) begin
            commit_reg          <= 1'B0;
            commit_pc_reg       <= 32'H0;
            commit_inst_reg     <= 32'H0;
            commit_halt_reg     <= 1'B0;
            commit_reg_we_reg   <= 1'B0;
            commit_reg_wa_reg   <= 5'H0;
            commit_reg_wd_reg   <= 32'H0;
            commit_dmem_we_reg  <= 1'B0;
            commit_dmem_wa_reg  <= 32'H0;
            commit_dmem_wd_reg  <= 32'H0;
        end
        else if (global_en) begin
            commit_reg          <= commit_wb;
            commit_pc_reg       <= pc_wb;    
            commit_inst_reg     <= inst_wb;   
            commit_halt_reg     <= inst_wb == `HALT_INST;   
            commit_reg_we_reg   <= rf_we_wb;   
            commit_reg_wa_reg   <= rf_wa_wb;   
            commit_reg_wd_reg   <= rf_wd_wb;   
            commit_dmem_we_reg  <= dmem_we_wb;   
            commit_dmem_wa_reg  <= alu_res_wb;   
            commit_dmem_wd_reg  <= dmem_wdata_wb;   
        end
    end

    assign commit           = commit_reg;
    assign commit_pc        = commit_pc_reg;
    assign commit_inst      = commit_inst_reg;
    assign commit_halt      = commit_halt_reg;
    assign commit_reg_we    = commit_reg_we_reg;
    assign commit_reg_wa    = commit_reg_wa_reg;
    assign commit_reg_wd    = commit_reg_wd_reg;
    assign commit_dmem_we   = commit_dmem_we_reg;
    assign commit_dmem_wa   = commit_dmem_wa_reg;
    assign commit_dmem_wd   = commit_dmem_wd_reg;

endmodule