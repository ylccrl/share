`include "./include/inst_type.vh"
`include "./include/logic_type.vh"

//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/08 18:47:23
// Design Name: 
// Module Name: DECODER
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

module DECODER (
    input                   [31 : 0]            inst,

    output                  [ 4 : 0]            alu_op,

    output                  [ 3 : 0]            dmem_access,

    output                  [31 : 0]            imm,

    output                  [ 4 : 0]            rf_ra_k,
    output                  [ 4 : 0]            rf_ra_j,
    output                  [ 4 : 0]            rf_ra_d,
    output                  [ 0 : 0]            rf_we,
    output                  [ 1 : 0]            rf_wd_sel,

    output                  [ 0 : 0]            dmem_we,

    output                  [ 0 : 0]            alu_src0_sel,
    output                  [ 0 : 0]            alu_src1_sel,

    output                  [ 5 : 0]            br_type
);
    ALU_OP my_alu_op(
        .inst(inst),
        .alu_op(alu_op)
    );
    assign dmem_access = inst[25:22];
    IMM my_imm(
        .inst(inst),
        .imm(imm)
    );
    assign rf_ra_k = inst[14:10];
    assign rf_ra_j = inst[9:5];
    //即JIRL指令,rd恒为1
    assign rf_ra_d = (inst[31:26]==6'b0101_01)?5'b1:inst[4:0];
    RF_DM my_rf_dm(
        .inst(inst),
        .rf_we(rf_we),
        .dmem_we(dmem_we),
        .rf_wd_sel(rf_wd_sel)
    );

    ALU_SRC_SEL my_alu_src_sel(
        .inst(inst),
        .alu_src0_sel(alu_src0_sel),
        .alu_src1_sel(alu_src1_sel)
    );
    assign br_type = inst[31:26];

  
endmodule

module ALU_OP(
    input                   [31 : 0]            inst,
    output        reg       [ 4 : 0]            alu_op
);
    always @(*) begin
        casez (inst[31:15])
            //19个指令有对应的ALU操作
            `ADD_W,`ADDI_W        :alu_op = `ADD;
            `SUB_W               :alu_op = `SUB;
            `SLT_,`SLTI_      :alu_op = `SLT;
            `SLTU_,`SLTUI_    :alu_op = `SLTU;
            `AND_,`ANDI_      :alu_op = `AND;
            `OR_,`ORI_        :alu_op = `OR;
            `XOR_,`XORI_      :alu_op = `XOR;
            `SLL_W,`SLLI_W        :alu_op = `SLL;
            `SRL_W,`SRLI_W        :alu_op = `SRL;
            `SRA_W,`SRAI_W        :alu_op = `SRA;

            //选立即数
            `LU12I_W            :alu_op = `SRC1;
            //剩下18个的指令都对应ADD
            `PCADDU12I              :alu_op = `ADD;

            `LD_B,`LD_H,`LD_W,`ST_B,`ST_H,`ST_W,`LD_BU,`LD_HU   :alu_op = `ADD;
            `JIRL                                       :alu_op = `ADD;
            `B,`BL                                      :alu_op = `ADD;
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU             :alu_op = `ADD;
            //未知指令
            default :alu_op = `none;
        endcase
    end
endmodule

module IMM(
    input                   [31 : 0]            inst,
    output       reg        [31 : 0]            imm
);
    always @(*) begin
        casez (inst[31:15])
            //si12
            `ADDI_W,`SLTI_,`SLTUI_                             
                :imm = {{20{inst[21]}},inst[21:10]};
            `LD_B,`LD_H,`LD_W,`ST_B,`ST_H,`ST_W,`LD_BU,`LD_HU       
                :imm = {{20{inst[21]}},inst[21:10]};

            //ui5
            `SLLI_W,`SRLI_W,`SRAI_W                            
                :imm = {{27{1'b0}},inst[14:10]};

            //ui12
            `ANDI_,`ORI_,`XORI_                                
                :imm = {{20{1'b0}},inst[21:10]};

            //si20低位扩展0
            `LU12I_W,`PCADDU12I                              
                :imm = {inst[24:5],{12'b0}};

            //offfs16
            `JIRL
                :imm = {{14{inst[25]}},inst[25:10],{2'b0}};
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU
                :imm = {{14{inst[25]}},inst[25:10],{2'b0}};

            //offs26
            `B,`BL
                :imm = {{4{inst[9]}},inst[9:0],inst[25:10],2'b0};

            default                                         
                :imm = 32'b0;
        endcase
    end
endmodule
//用于生成寄存器写使能、写选择和内存写使能
module RF_DM(
    input                   [31 : 0]            inst,
    output        reg       [ 0 : 0]            rf_we,
    output        reg       [ 0 : 0]            dmem_we,
    output        reg       [ 1 : 0]            rf_wd_sel
);
    //对于rf_we
    //1'b1为写使能有效，1'b0为写使能无效

    //对于rf_wd_sel
    //2'b00选pc_add4
    //2'b01选alu_res
    //2'b10选dmem_rdata
    //2'b11选0
    always @(*) begin
        casez(inst[31:15])
            //第一次实验中所有指令均是把ALU结果写入寄存器的
            `ADD_W,`ADDI_W,`SUB_W,`SLT_,`SLTU_ ,`AND_,`OR_,`XOR_,`SLL_W,`SRL_W,`SRA_W,`SLLI_W,`SRLI_W,`SRAI_W,`SLTI_,`SLTUI_,`ANDI_,`ORI_,`XORI_,`LU12I_W,`PCADDU12I:begin
                rf_we = 1'b1;
                rf_wd_sel = 2'b01;
                dmem_we = 1'b0;
            end
            //L指令读取内存，将dmem_rdata写入寄存器
            `LD_B,`LD_H,`LD_W,`LD_BU,`LD_HU:begin
                rf_we = 1'b1;
                rf_wd_sel = 2'b10;
                dmem_we = 1'b0;
            end
            //特殊的跳转指令，将PC+4写入寄存器
            `JIRL,`BL:begin
                rf_we = 1'b1;
                rf_wd_sel = 2'b00;
                dmem_we = 1'b0;
            end
            //S指令写入内存，不修改寄存器
            `ST_B,`ST_H,`ST_W:begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b1;
            end
            //以下跳转指令只跳转，不修改寄存器,不修改内存
            `B:begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b0;
            end
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU:begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b0;
            end
                    
            default :begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b0;
            end
        endcase
    end
endmodule

module ALU_SRC_SEL(
    input                   [31 : 0]            inst,
    output        reg       [ 0 : 0]            alu_src0_sel,
    output        reg       [ 0 : 0]            alu_src1_sel
);
//对于alu_src0_sel,0表示选寄存器，1表示选PC
//对于alu_src1_sel,0表示选寄存器，1表示选立即数
    always @(*) begin
        casez(inst[31:15]) 
            //选rj和rk
            `ADD_W,`SUB_W,`SLT_,`SLTU_,`AND_,`OR_,`XOR_,`SLL_W,`SRL_W,`SRA_W:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b0;
            end

            //选rj和立即数
            `SLLI_W,`SRLI_W,`SRAI_W,`SLTI_,`SLTUI_,`ADDI_W,`ANDI_,`ORI_,`XORI_:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b1;
            end
            `LD_B,`LD_H,`LD_W,`ST_B,`ST_H,`ST_W,`LD_BU,`LD_HU:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b1;
            end
            `JIRL:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b1;
            end

            //选立即数
            `LU12I_W:begin
                    alu_src0_sel = 1'b0;
                    alu_src1_sel = 1'b1;
            end

        //选PC和立即数
            `PCADDU12I:begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b1;
            end
            `B,`BL:begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b1;
            end
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU:begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b1;
            end

        //异常
            default :begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b0;
            end
        endcase
    end
endmodule

