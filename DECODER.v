`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/03 08:10:59
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
`define NONE                5'B11111
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


`define ADDW       17'b0000_0000_0001_0000_0
`define ADDIW      17'b0000_0010_10xx_xxxx_x
`define SUBW       17'b0000_0000_0001_0001_0
`define SLT_LAR    17'b0000_0000_0001_0010_0
`define SLTU_LAR   17'b0000_0000_0001_0010_1
`define AND_LAR    17'b0000_0000_0001_0100_1
`define OR_LAR     17'b0000_0000_0001_0101_0
`define XOR_LAR    17'b0000_0000_0001_0101_1
`define SLLW       17'b0000_0000_0001_0111_0
`define SRLW       17'b0000_0000_0001_0111_1
`define SRAW       17'b0000_0000_0001_1000_0
`define SLLIW      17'b0000_0000_0100_00_001
`define SRLIW      17'b0000_0000_0100_01_001
`define SRAIW      17'b0000_0000_0100_10_001
`define SLTI       17'b0000_0010_00xx_xxxx_x
`define SLTUI      17'b0000_0010_01xx_xxxx_x
`define ANDI       17'b0000_0011_01xx_xxxx_x
`define ORI        17'b0000_0011_10xx_xxxx_x
`define XORI       17'b0000_0011_11xx_xxxx_x
`define LU12IW     17'b0001_010x_xxxx_xxxx_x
`define PCADDU12I  17'b0001_110x_xxxx_xxxx_x



`define LDW        17'b0010_1000_10xx_xxxx_x
`define STW        17'b0010_1001_10xx_xxxx_x
`define JIRL       17'b0100_11xx_xxxx_xxxx_x
`define B          17'b0101_00xx_xxxx_xxxx_x
`define BL         17'b0101_01xx_xxxx_xxxx_x
`define BEQ        17'b0101_10xx_xxxx_xxxx_x
`define BNE        17'b0101_11xx_xxxx_xxxx_x
`define BLT        17'b0110_00xx_xxxx_xxxx_x
`define BGE        17'b0110_01xx_xxxx_xxxx_x
`define BLTU       17'b0110_10xx_xxxx_xxxx_x
`define BGEU       17'b0110_11xx_xxxx_xxxx_x


module DECODER (
    input                   [31 : 0]            inst,

    output                  [ 4 : 0]            alu_op,
    output                  [31 : 0]            imm,

    output                  [ 4 : 0]            rf_ra0,
    output                  [ 4 : 0]            rf_ra1,
    output                  [ 4 : 0]            rf_wa,
    output                  [ 0 : 0]            rf_we,

    output                  [ 0 : 0]            alu_src0_sel,
    output                  [ 0 : 0]            alu_src1_sel
);
    ALU_OP my_alu_op(
        .inst(inst),
        .alu_op(alu_op)
    );
    IMM my_imm(
        .inst(inst),
        .imm(imm)
    );
    ALU_SRC_SEL my_alu_src_sel(
        .inst(inst),
        .alu_src0_sel(alu_src0_sel),
        .alu_src1_sel(alu_src1_sel)
    );
    RF_WE my_rf_we(
        .inst(inst),
        .rf_we(rf_we)
    );
    assign rf_ra1 = inst[14:10];
    assign rf_ra0 = (inst[31:15]==`LU12IW)?5'b0:inst[9:5];
    assign rf_wa = inst[4:0];
    
endmodule

module ALU_OP(
    input                   [31 : 0]            inst,
    output                  [ 4 : 0]            alu_op
);
//19个指令有对应的ALU操作
    reg [4:0] alu_op_t;
    always @(*) begin
        casex (inst[31:15])
            `ADDW,`ADDIW        :alu_op_t = `ADD;
            `SUBW               :alu_op_t = `SUB;
            `SLT_LAR,`SLTI      :alu_op_t = `SLT;
            `SLTU_LAR,`SLTUI    :alu_op_t = `SLTU;
            `AND_LAR,`ANDI      :alu_op_t = `AND;
            `OR_LAR,`ORI        :alu_op_t = `OR;
            `XOR_LAR,`XORI      :alu_op_t = `XOR;
            `SLLW,`SLLIW        :alu_op_t = `SLL;
            `SRLW,`SRLIW        :alu_op_t = `SRL;
            `SRAW,`SRAIW        :alu_op_t = `SRA;

            `LU12IW,`PCADDU12I  :alu_op_t = `ADD;
            default:    alu_op_t = `NONE;
        endcase
    end
    assign alu_op = alu_op_t;
endmodule
module IMM(
    input                   [31 : 0]            inst,
    output                  [31 : 0]            imm
);
    reg [31:0] imm_t;
    always @(*) begin
        casex (inst[31:15])
            //si12
            `ADDIW,`SLTI,`SLTUI           :imm_t = {{20{inst[21]}},inst[21:10]};
            //ui5
            `SLLIW,`SRLIW,`SRAIW          :imm_t = {{27{1'b0}},inst[14:10]};
            //ui12
            `ANDI,`ORI,`XORI              :imm_t = {{20{1'b0}},inst[21:10]};
            //si20低位扩展0
            `LU12IW,`PCADDU12I            :imm_t = {inst[24:5],{12'b0}};

            default                       :imm_t = 0;
        endcase
    end
    assign imm = imm_t;
endmodule
module ALU_SRC_SEL(
    input                   [31 : 0]            inst,
    output                  [ 0 : 0]            alu_src0_sel,
    output                  [ 0 : 0]            alu_src1_sel
);
//对于alu_src0_sel,0表示选寄存器，1表示选PC
//对于alu_src1_sel,0表示选寄存器，1表示选立即数
    reg [0:0] alu_src0_sel_t,alu_src1_sel_t;
    always @(*) begin
        casex(inst[31:15]) 
            `ADDW,`SUBW,`SLT_LAR,`SLTU_LAR,`AND_LAR,`OR_LAR,`XOR_LAR,`SLLW,`SRLW,`SRAW:begin
                alu_src0_sel_t = 1'b0;
                alu_src1_sel_t = 1'b0;
            end

            `SLLIW,`SRLIW,`SRAIW:begin
                alu_src0_sel_t = 1'b0;
                alu_src1_sel_t = 1'b1;
            end
            `SLTI,`SLTUI,`ADDIW:begin
                alu_src0_sel_t = 1'b0;
                alu_src1_sel_t = 1'b1;
            end
            `ANDI,`ORI,`XORI:begin
                alu_src0_sel_t = 1'b0;
                alu_src1_sel_t = 1'b1;
            end

            `LU12IW:begin
                alu_src0_sel_t = 1'b0;
                alu_src1_sel_t = 1'b1;
            end

            `PCADDU12I:begin
                alu_src0_sel_t = 1'b1;
                alu_src1_sel_t = 1'b1;
            end

            default :begin
                alu_src0_sel_t = 1'b1;
                alu_src1_sel_t = 1'b0;
            end
        endcase
    end
    assign alu_src0_sel = alu_src0_sel_t;
    assign alu_src1_sel = alu_src1_sel_t;
endmodule
module RF_WE(
    input                   [31 : 0]            inst,
    output                  [ 0 : 0]            rf_we
);
//当指令为本次实验所用指令时，写使能有效
    reg [0:0] rf_we_t;
    always @(*) begin
        casex(inst[31:15])
            `ADDW,`ADDIW,`SUBW,`SLT_LAR,`SLTU_LAR ,`AND_LAR,`OR_LAR,`XOR_LAR,`SLLW,`SRLW,`SRAW,`SLLIW,`SRLIW,`SRAIW,`SLTI,`SLTUI,`ANDI,`ORI,`XORI,`LU12IW,`PCADDU12I:
                rf_we_t = 1'b1;
            default :
                rf_we_t = 1'b0;
        endcase
    end
    assign rf_we = rf_we_t;
endmodule