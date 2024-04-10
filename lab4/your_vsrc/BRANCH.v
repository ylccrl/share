

`include "br_type.vh"
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/08 18:47:23
// Design Name: 
// Module Name: BRANCH
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


module BRANCH(
    //分支跳转的类型
    input   [ 3: 0]     br_type,
    //来自寄存器堆的两个数据,br_src0:rj,br_src1:rd
    input   [31: 0]     br_src0,
    input   [31: 0]     br_src1,
    //npc选择器的控制信号
    output  [ 1: 0]     npc_sel
    );
    reg [1:0] npc_sel_t;
always @(*) begin
    //JIRL:1'b1
    //B、BL:1'b1
    //BEQ、BNE、BLT、BGE、BLTU、BGEU:满足条件1'b1,不满足1'b0
    //default:1'b0,说明是其他指令，但还存在问题
    case(br_type)
        `JIRL_B  :
            npc_sel_t = 1'b1;

        `B_B,`BL_B     :
            npc_sel_t = 1'b1;

        `BEQ_B   :
            npc_sel_t = (br_src0==br_src1)?1'b1:1'b0;
        `BNE_B   :
            npc_sel_t = (br_src0!=br_src1)?1'b1:1'b0;
        `BLT_B   :
            npc_sel_t = ($signed(br_src0)<$signed(br_src1))?1'b1:1'b0;
        `BGE_B   :
            npc_sel_t = ($signed(br_src0)>=$signed(br_src1))?1'b1:1'b0;
        `BLTU_B  :
            npc_sel_t = (br_src0<br_src1)?1'b1:1'b0;
        `BGEU_T  :
            npc_sel_t = (br_src0>=br_src1)?1'b1:1'b0;

        default :
            npc_sel_t = 1'b0;
    endcase
end
endmodule
