
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2024/04/07 14:08:47
// Design Name: 
// Module Name: ADD4
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


module ADD4(
    input               [31 : 0]    pc,

    output      reg     [31 : 0]    npc    
);

always @(*) begin
    npc = pc + 4;
end

endmodule
