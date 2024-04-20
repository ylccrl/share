module NPC_MUX(
    input           [31:0]          pc_add4,
    input           [31:0]          pc_offset,
    input           [ 0:0]          npc_sel,

    output          [31:0]          npc
    );
    //npc_sel为1选pc_offset，为0选pc_add4
    //与BRANCH.v中保持一致
    assign npc = npc_sel?pc_offset:pc_add4;
endmodule