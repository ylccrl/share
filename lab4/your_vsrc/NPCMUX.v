
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/08 18:47:23
// Design Name: 
// Module Name: NPCMUX
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


module NPCMUX(
    input           [31:0]          pc_add4,
    input           [31:0]          pc_offset,
    input           [ 0:0]          npc_sel,

    output          [31:0]          npc
    );
    //npc_sel为1选pc_offset，为0选pc_add4
    //与BRANCH.v中保持一致
    assign npc = npc_sel?pc_offset:pc_add4;
endmodule
