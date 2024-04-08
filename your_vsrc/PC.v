
`define BEGIN_ADDR 32'h1C00_0000

module PC (
    input                   [ 0 : 0]            clk,
    input                   [ 0 : 0]            rst,
    input                   [ 0 : 0]            en,
    input                   [31 : 0]            npc,

    output      reg         [31 : 0]            pc
);
always @(posedge clk) begin
    if(rst)
        pc <= `BEGIN_ADDR;
    else if(en)
        pc <= npc;
    else
        pc <= pc;
end
endmodule

