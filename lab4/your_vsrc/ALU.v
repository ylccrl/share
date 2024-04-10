
`include "logic_type.vh"

//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/09 15:27:30
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


module ALU (
    input                   [31 : 0]            alu_src0,
    input                   [31 : 0]            alu_src1,
    input                   [ 4 : 0]            alu_op,

    output      reg         [31 : 0]            alu_res
);
    always @(*) begin
        case(alu_op)
            `ADD    :alu_res = alu_src0 + alu_src1;
            `SUB    :alu_res = alu_src0 - alu_src1;
            `SLT    :alu_res = {{31'h0},{$signed(alu_src0)<$signed(alu_src1)}} ;
            `SLTU   :alu_res = {{31'h0},{alu_src0 < alu_src1}};
            `AND    :alu_res = alu_src0 & alu_src1;
            `OR     :alu_res = alu_src0 | alu_src1;
            `XOR    :alu_res = alu_src0 ^ alu_src1;
            `SLL    :alu_res = alu_src0 << alu_src1[4:0];
            `SRL    :alu_res = alu_src0 >> alu_src1[4:0];
            `SRA    :alu_res = $signed(alu_src0) >>> alu_src1[4:0];
            `SRC0   :alu_res = alu_src0;
            `SRC1   :alu_res = alu_src1;
            default :alu_res = 32'H0;
        endcase
    end
endmodule
