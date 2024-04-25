`define JIRL_B     6'b010011
`define B_B        6'b010100
`define BL_B       6'b010101
`define BEQ_B      6'b010110
`define BNE_B      6'b010111
`define BLT_B      6'b011000
`define BGE_B      6'b011001
`define BLTU_B     6'b011010
`define BGEU_B     6'b011011

module BRANCH(
    //分支跳转的类型
    input   [ 5: 0]     br_type,
    //来自寄存器堆的两个数据,br_src0:rj,br_src1:rd
    input   [31: 0]     br_src0,
    input   [31: 0]     br_src1,
    //npc选择器的控制信号
    output reg [ 0: 0]     npc_sel
    );
    //对于npc_sel,为1'b0选择pc_add4,为1'b1选择pc_offset
    always @(*) begin
        //JIRL:1'b1
        //B、BL:1'b1
        //BEQ、BNE、BLT、BGE、BLTU、BGEU:满足条件1'b1,不满足1'b0
        case(br_type)
            `JIRL_B   :
                npc_sel = 1'b1;
            `B_B,`BL_B:
                npc_sel = 1'b1;
            `BEQ_B    :
                npc_sel = (br_src0==br_src1)?1'b1:1'b0;
            `BNE_B    :
                npc_sel = (br_src0!=br_src1)?1'b1:1'b0;
            `BLT_B    :
                npc_sel = ($signed(br_src0)<$signed(br_src1))?1'b1:1'b0;
            `BGE_B    :
                npc_sel = ($signed(br_src0)>=$signed(br_src1))?1'b1:1'b0;
            `BLTU_B   :
                npc_sel = (br_src0<br_src1)?1'b1:1'b0;
            `BGEU_B   :
                npc_sel = (br_src0>=br_src1)?1'b1:1'b0;
            default   :
                npc_sel = 1'b0;
        endcase
    end
endmodule