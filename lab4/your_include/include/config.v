`ifndef _CONFIG_V_
`define _CONFIG_V_

// PC init/reset address
`define PC_INIT             32'H1c000000

`define HALT_INST           32'H80000000

// logic type
`define ADD                 5'B00000
`define SUB                 5'B00010
`define SLT                 5'B00100
`define SLTU                5'B00101
`define NOR                 5'B01000
`define AND                 5'B01001
`define OR                  5'B01010
`define XOR                 5'B01011
`define SLL                 5'B01110
`define SRL                 5'B01111
`define SRA                 5'B10000
`define SRC0                5'B10001
`define SRC1                5'B10010

`endif

