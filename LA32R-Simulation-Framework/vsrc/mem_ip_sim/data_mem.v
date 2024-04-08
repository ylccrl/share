`include "configs.vh"

import "DPI-C" function void expose_memory(int _dataMemDepth, reg [31 : 0] _mem [0 : (1 << `DATA_MEM_DEPTH) - 1]);

module
    DataMem(
        input           [`DATA_MEM_DEPTH - 1 : 0]           a,
        input           [31 : 0]                            d,
        input                                               clk,
        input                                               we,
        output          [31 : 0]                            spo
    );

    reg                 [31 : 0]                            mem             [0 : (1 << `DATA_MEM_DEPTH) - 1];

    initial begin
        $readmemh(`DATA_MEM_FILE, mem);
    end

    always @(posedge clk) if(`CORE_TYPE == `PIPELINE) expose_memory(`DATA_MEM_DEPTH, mem);
    always @(negedge clk) if(`CORE_TYPE != `PIPELINE) expose_memory(`DATA_MEM_DEPTH, mem);

    always @(posedge clk) begin
        if(we) mem[a] <= d;
    end

    assign spo = mem[a];

endmodule