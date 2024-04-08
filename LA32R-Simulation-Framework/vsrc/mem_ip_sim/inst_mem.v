`include "configs.vh"

module
    InstMem(
        input           [`INST_MEM_DEPTH - 1 : 0]           a,
        output          [31 : 0]                            spo
    );

    reg                 [31 : 0]                            mem             [0 : (1 << `INST_MEM_DEPTH) - 1];

    initial begin
        $readmemh(`INST_MEM_FILE, mem);
    end

    assign spo = mem[a];

endmodule