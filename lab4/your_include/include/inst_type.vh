`ifndef INST_TYPE
`define INST_TYPE

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

`endif 