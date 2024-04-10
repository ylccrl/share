
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/03 14:25:06
// Design Name: 
// Module Name: DECODE
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// ADDWitional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
`define PCADDWU12I   7'b0001110
`define LU12I       7'b0001010

`define XORWI        10'b0000_0011_11
`define ORWI         10'b0000_0011_10
`define ANDWI        10'b0000_0011_01
`define ADDWI        10'b0000_0010_10
`define SLTWUI       10'b0000_0010_01
`define SLTWI        10'b0000_0010_00

`define SRAWI        17'b0000_0000_0100_1000_1
`define SRLWI        17'b0000_0000_0100_0100_1
`define SLLWI        17'b0000_0000_0100_0000_1

`define SRAW         17'b0000_0000_0001_1000_0
`define SRLW         17'b0000_0000_0001_0111_1
`define SLLW         17'b0000_0000_0001_0111_0
`define XORW         17'b0000_0000_0001_0101_1
`define ORW          17'b0000_0000_0001_0101_0
`define ANDW         17'b0000_0000_0001_0100_1
`define SLTWU        17'b0000_0000_0001_0010_1
`define SLTW         17'b0000_0000_0001_0010_0
`define SUBW         17'b0000_0000_0001_0001_0
`define ADDW         17'b0000_0000_0001_0000_0

module DECODE (
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

localparam  atype_7b = 32'h1000_0000;
localparam  btype_10b = 32'h0200_0000;
localparam  ctype_17b = 32'h0040_0000;
localparam  dtype_17b = 32'h0010_0000;

reg [31 : 0] imm_t;
reg [ 4 : 0] alu_op_t, rf_ra0_t, rf_ra1_t, rf_wa_t;
reg [ 0 : 0] rf_we_t, alu_src0_sel_t, alu_src1_sel_t;

always @(*) begin
    imm_t = 0; alu_op_t = 0; rf_ra0_t = 0; rf_ra1_t = 0; rf_wa_t = 0; rf_we_t = 0; alu_src0_sel_t = 0; alu_src1_sel_t = 0;
    if(inst >= atype_7b) begin 
        case(inst[31:25])
            `PCADDWU12I : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                alu_src0_sel_t = 1;
                alu_src1_sel_t = 1;
                imm_t = {inst[24:5],12'b0};
                alu_op_t = 5'B00000;
            end
            `LU12I : begin
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                alu_src1_sel_t = 1;
                imm_t = {inst[24:5],12'b0};
                alu_op_t = 5'B00000;
            end
            default: begin
                rf_ra0_t = 0; rf_ra1_t = 0;
            end
        endcase 
    end
    else if(inst < atype_7b && inst >= btype_10b) begin
        case(inst[31:22]) 
            `XORWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {20'b0,inst[21:10]};
                alu_op_t = 5'B01011;
            end
            `ORWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {20'b0,inst[21:10]};
                alu_op_t = 5'B01010;
            end
            `ANDWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {20'b0,inst[21:10]};
                alu_op_t = 5'B01001;
            end
            `ADDWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {{20{inst[21]}},inst[21:10]};
                alu_op_t = 5'B00000;
            end
            `SLTWUI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {{20{inst[21]}},inst[21:10]};
                alu_op_t = 5'B00101;
            end
            `SLTWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {{20{inst[21]}},inst[21:10]};
                alu_op_t = 5'B00100;
            end
            default:begin
                rf_ra1_t = 0;
            end
        endcase
    end
    else if(inst < btype_10b && inst >= ctype_17b) begin
        case(inst[31:15])
            `SRAWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {27'b0,inst[14:10]};
                alu_op_t = 5'B10000;
            end
            `SRLWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {27'b0,inst[14:10]};
                alu_op_t = 5'B01111;
            end
            `SLLWI : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                alu_src1_sel_t = 1;
                imm_t = {27'b0,inst[14:10]};
                alu_op_t = 5'B01110;
            end
            default : begin
                rf_ra1_t = 0;
            end
        endcase
    end
    else if(inst < ctype_17b && inst >= dtype_17b) begin
        case(inst[31:15])
            `SRAW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B10000;
            end
            `SRLW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B01111;
            end
            `SLLW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B01110;
            end
            `XORW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B01011;
            end
            `ORW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B01010;
            end
            `ANDW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B01001;
            end
            `SLTWU : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B00101;
            end
            `SLTW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B00100;
            end
            `SUBW : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B00010;
            end
            `SLTWU : begin 
                rf_wa_t = inst[4:0];
                rf_we_t = 1;
                rf_ra0_t = inst[9:5];
                rf_ra1_t = inst[14:10];
                alu_op_t = 5'B00000;
            end
            default : begin
                imm_t = 0; alu_op_t = 0; rf_ra0_t = 0; rf_ra1_t = 0; rf_wa_t = 0; rf_we_t = 0; alu_src0_sel_t = 0; alu_src1_sel_t = 0;
            end
        endcase
    end
end

assign alu_op = alu_op_t;
assign imm = imm_t;
assign rf_ra0 = rf_ra0_t;
assign rf_ra1 = rf_ra1_t;
assign rf_wa = rf_wa_t;
assign rf_we = rf_we_t;
assign alu_src0_sel = alu_src0_sel_t;
assign alu_src1_sel = alu_src1_sel_t;

endmodule