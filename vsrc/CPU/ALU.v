`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/06 20:50:48
// Design Name: 
// Module Name: ALU
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


module ALU (
    input                   [31 : 0]            alu_src0,
    input                   [31 : 0]            alu_src1,
    input                   [ 4 : 0]            alu_op,

    output      reg         [31 : 0]            alu_res
);
reg [31:0] temp;
    always @(*) begin
        case(alu_op)
            `ADD    :alu_res = alu_src0 + alu_src1;
            `SUB    :alu_res = alu_src0 - alu_src1;
            `SLT    :begin
                if(alu_src0[31]^alu_src1[31])
                    alu_res = alu_src0[31]==1?1:0;
                else begin
                    temp = alu_src0 - alu_src1;
                    alu_res = temp[31];
                end
            end
            `SLTU   :alu_res = alu_src0 < alu_src1;
            `AND    :alu_res = alu_src0 & alu_src1;
            `OR     :alu_res = alu_src0 | alu_src1;
            `XOR    :alu_res = alu_src0 ^ alu_src1;
            `SLL    :alu_res = alu_src0 << alu_src1[4:0];
            `SRL    :alu_res = alu_src0 >> alu_src1[4:0];
            `SRA    :begin
                if(alu_src0[31]==0)
                    alu_res = alu_src0 >> alu_src1[4:0];
                else begin
                    temp = 32-alu_src1[4:0];
                    alu_res = (alu_src0 >> alu_src1[4:0])|(32'hffffffff<<temp);
                end
            end
            `SRC0   :alu_res = alu_src0;
            `SRC1   :alu_res = alu_src1;
            default :alu_res = 32'H0;
        endcase
    end
endmodule
