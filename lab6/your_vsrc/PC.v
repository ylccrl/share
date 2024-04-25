`define PC_INIT             32'H1c000000

module PC (
    input                   [ 0 : 0]            clk,
    input                   [ 0 : 0]            rst,
    input                   [ 0 : 0]            en,
    input                   [31 : 0]            npc,
    input                   [ 0 : 0]            stall,
    input                   [ 0 : 0]            flush,
    output      reg         [31 : 0]            pc
);
always @(posedge clk) begin
    if(rst)
        pc <= `PC_INIT;
    else if(en) begin
        if(flush)
            pc <= `PC_INIT;
        else if(stall)
            pc <= pc;
        else
            pc <= npc;
    end
    else
        pc <= pc;
end
endmodule