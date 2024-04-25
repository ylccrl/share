`define ADD_W       17'b0000_0000_0001_0000_0
`define ADDI_W      17'b0000_0010_10zz_zzzz_z
`define SUB_W       17'b0000_0000_0001_0001_0
`define SLT_        17'b0000_0000_0001_0010_0
`define SLTU_       17'b0000_0000_0001_0010_1
`define AND_        17'b0000_0000_0001_0100_1
`define OR_         17'b0000_0000_0001_0101_0
`define XOR_        17'b0000_0000_0001_0101_1
`define SLL_W       17'b0000_0000_0001_0111_0
`define SRL_W       17'b0000_0000_0001_0111_1
`define SRA_W       17'b0000_0000_0001_1000_0
`define SLLI_W      17'b0000_0000_0100_00_001
`define SRLI_W      17'b0000_0000_0100_01_001
`define SRAI_W      17'b0000_0000_0100_10_001
`define SLTI_       17'b0000_0010_00zz_zzzz_z
`define SLTUI_      17'b0000_0010_01zz_zzzz_z
`define ANDI_       17'b0000_0011_01zz_zzzz_z
`define ORI_        17'b0000_0011_10zz_zzzz_z
`define XORI_       17'b0000_0011_11zz_zzzz_z

`define LU12I_W     17'b0001_010z_zzzz_zzzz_z
`define PCADDU12I   17'b0001_110z_zzzz_zzzz_z

`define LD_B        17'b0010_1000_00zz_zzzz_z
`define LD_H        17'b0010_1000_01zz_zzzz_z
`define LD_W        17'b0010_1000_10zz_zzzz_z
`define ST_B        17'b0010_1001_00zz_zzzz_z
`define ST_H        17'b0010_1001_01zz_zzzz_z
`define ST_W        17'b0010_1001_10zz_zzzz_z
`define LD_BU       17'b0010_1010_00zz_zzzz_z
`define LD_HU       17'b0010_1010_01zz_zzzz_z
      
`define JIRL        17'b0100_11zz_zzzz_zzzz_z

`define B           17'b0101_00zz_zzzz_zzzz_z
`define BL          17'b0101_01zz_zzzz_zzzz_z

`define BEQ         17'b0101_10zz_zzzz_zzzz_z
`define BNE         17'b0101_11zz_zzzz_zzzz_z
`define BLT         17'b0110_00zz_zzzz_zzzz_z
`define BGE         17'b0110_01zz_zzzz_zzzz_z
`define BLTU        17'b0110_10zz_zzzz_zzzz_z
`define BGEU        17'b0110_11zz_zzzz_zzzz_z

// logic type
`define none                5'b11111

`define ADD                 5'B00000    
`define SUB                 5'B00010   
`define SLT                 5'B00100
`define SLTU                5'B00101
`define AND                 5'B01001
`define OR                  5'B01010
`define XOR                 5'B01011
`define SLL                 5'B01110   
`define SRL                 5'B01111    
`define SRA                 5'B10000  
`define SRC0                5'B10001
`define SRC1                5'B10010

module DECODER (
    input                   [31 : 0]            inst,

    output                  [ 4 : 0]            alu_op,

    output                  [ 3 : 0]            dmem_access,

    output                  [31 : 0]            imm,

    output                  [ 4 : 0]            rf_ra0,//rj
    output                  [ 4 : 0]            rf_ra1,//rk或rd
    output                  [ 4 : 0]            rf_wa,
    output                  [ 0 : 0]            rf_we,
    output                  [ 1 : 0]            rf_wd_sel,

    output                  [ 0 : 0]            dmem_we,

    output                  [ 0 : 0]            alu_src0_sel,
    output                  [ 0 : 0]            alu_src1_sel,

    output                  [ 5 : 0]            br_type
);
    ALU_OP my_alu_op(
        .inst(inst),
        .alu_op(alu_op)
    );
    assign dmem_access = inst[25:22];
    IMM my_imm(
        .inst(inst),
        .imm(imm)
    );
    //当指令不需要rk时，ra1为rd的地址
    assign rf_ra1 = (inst[31:20]!=12'b0000_0000_0001)?inst[4:0]:inst[14:10];
    //rj始终为rj
    assign rf_ra0 = inst[9:5];
    //即BL指令,rd恒为1
    assign rf_wa = (inst[31:26]==6'b0101_01)?5'b1:inst[4:0];
    RF_DM my_rf_dm(
        .inst(inst),
        .rf_we(rf_we),
        .dmem_we(dmem_we),
        .rf_wd_sel(rf_wd_sel)
    );
    ALU_SRC_SEL my_alu_src_sel(
        .inst(inst),
        .alu_src0_sel(alu_src0_sel),
        .alu_src1_sel(alu_src1_sel)
    );
    assign br_type = inst[31:26];

endmodule

module ALU_OP(
    input                   [31 : 0]            inst,
    output        reg       [ 4 : 0]            alu_op
);
    always @(*) begin
        casez (inst[31:15])
            //19个指令有对应的ALU操作
            `ADD_W,`ADDI_W        :alu_op = `ADD;
            `SUB_W               :alu_op = `SUB;
            `SLT_,`SLTI_      :alu_op = `SLT;
            `SLTU_,`SLTUI_    :alu_op = `SLTU;
            `AND_,`ANDI_      :alu_op = `AND;
            `OR_,`ORI_        :alu_op = `OR;
            `XOR_,`XORI_      :alu_op = `XOR;
            `SLL_W,`SLLI_W        :alu_op = `SLL;
            `SRL_W,`SRLI_W        :alu_op = `SRL;
            `SRA_W,`SRAI_W        :alu_op = `SRA;

            //选立即数
            `LU12I_W            :alu_op = `SRC1;
            //剩下18个的指令都对应ADD
            `PCADDU12I              :alu_op = `ADD;

            `LD_B,`LD_H,`LD_W,`ST_B,`ST_H,`ST_W,`LD_BU,`LD_HU   :alu_op = `ADD;
            `JIRL                                       :alu_op = `ADD;
            `B,`BL                                      :alu_op = `ADD;
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU             :alu_op = `ADD;
            //未知指令
            default :alu_op = `none;
        endcase
    end
endmodule

module IMM(
    input                   [31 : 0]            inst,
    output       reg        [31 : 0]            imm
);
    always @(*) begin
        casez (inst[31:15])
            //si12
            `ADDI_W,`SLTI_,`SLTUI_                             
                :imm = {{20{inst[21]}},inst[21:10]};
            `LD_B,`LD_H,`LD_W,`ST_B,`ST_H,`ST_W,`LD_BU,`LD_HU       
                :imm = {{20{inst[21]}},inst[21:10]};

            //ui5
            `SLLI_W,`SRLI_W,`SRAI_W                            
                :imm = {{27{1'b0}},inst[14:10]};

            //ui12
            `ANDI_,`ORI_,`XORI_                                
                :imm = {{20{1'b0}},inst[21:10]};

            //si20低位扩展0
            `LU12I_W,`PCADDU12I                              
                :imm = {inst[24:5],{12'b0}};

            //offfs16
            `JIRL
                :imm = {{14{inst[25]}},inst[25:10],{2'b0}};
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU
                :imm = {{14{inst[25]}},inst[25:10],{2'b0}};

            //offs26
            `B,`BL
                :imm = {{4{inst[9]}},inst[9:0],inst[25:10],2'b0};

            default                                         
                :imm = 32'b0;
        endcase
    end
endmodule
//用于生成寄存器写使能、写选择和内存写使能
module RF_DM(
    input                   [31 : 0]            inst,
    output        reg       [ 0 : 0]            rf_we,
    output        reg       [ 0 : 0]            dmem_we,
    output        reg       [ 1 : 0]            rf_wd_sel
);
    //对于rf_we
    //1'b1为写使能有效，1'b0为写使能无效

    //对于rf_wd_sel
    //2'b00选pc_add4
    //2'b01选alu_res
    //2'b10选dmem_rdata
    //2'b11选0
    always @(*) begin
        casez(inst[31:15])
            //第一次实验中所有指令均是把ALU结果写入寄存器的
            `ADD_W,`ADDI_W,`SUB_W,`SLT_,`SLTU_ ,`AND_,`OR_,`XOR_,`SLL_W,`SRL_W,`SRA_W,`SLLI_W,`SRLI_W,`SRAI_W,`SLTI_,`SLTUI_,`ANDI_,`ORI_,`XORI_,`LU12I_W,`PCADDU12I:begin
                rf_we = 1'b1;
                rf_wd_sel = 2'b01;
                dmem_we = 1'b0;
            end
            //L指令读取内存，将dmem_rdata写入寄存器
            `LD_B,`LD_H,`LD_W,`LD_BU,`LD_HU:begin
                rf_we = 1'b1;
                rf_wd_sel = 2'b10;
                dmem_we = 1'b0;
            end
            //特殊的跳转指令，将PC+4写入寄存器
            `JIRL,`BL:begin
                rf_we = 1'b1;
                rf_wd_sel = 2'b00;
                dmem_we = 1'b0;
            end
            //S指令写入内存，不修改寄存器
            `ST_B,`ST_H,`ST_W:begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b1;
            end
            //以下跳转指令只跳转，不修改寄存器,不修改内存
            `B:begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b0;
            end
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU:begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b0;
            end
                    
            default :begin
                rf_we = 1'b0;
                rf_wd_sel = 2'b11;
                dmem_we = 1'b0;
            end
        endcase
    end
endmodule

module ALU_SRC_SEL(
    input                   [31 : 0]            inst,
    output        reg       [ 0 : 0]            alu_src0_sel,
    output        reg       [ 0 : 0]            alu_src1_sel
);
//对于alu_src0_sel,0表示选寄存器，1表示选PC
//对于alu_src1_sel,0表示选寄存器，1表示选立即数
    always @(*) begin
        casez(inst[31:15]) 
            //选rj和rk
            `ADD_W,`SUB_W,`SLT_,`SLTU_,`AND_,`OR_,`XOR_,`SLL_W,`SRL_W,`SRA_W:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b0;
            end

            //选rj和立即数
            `SLLI_W,`SRLI_W,`SRAI_W,`SLTI_,`SLTUI_,`ADDI_W,`ANDI_,`ORI_,`XORI_:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b1;
            end
            `LD_B,`LD_H,`LD_W,`ST_B,`ST_H,`ST_W,`LD_BU,`LD_HU:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b1;
            end
            `JIRL:begin
                alu_src0_sel = 1'b0;
                alu_src1_sel = 1'b1;
            end

            //选立即数
            `LU12I_W:begin
                    alu_src0_sel = 1'b0;
                    alu_src1_sel = 1'b1;
            end

        //选PC和立即数
            `PCADDU12I:begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b1;
            end
            `B,`BL:begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b1;
            end
            `BEQ,`BNE,`BLT,`BGE,`BLTU,`BGEU:begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b1;
            end

        //异常
            default :begin
                alu_src0_sel = 1'b1;
                alu_src1_sel = 1'b0;
            end
        endcase
    end
endmodule