// instruction memory size: 2 ^ INST_MEM_DEPTH * 4B
`define INST_MEM_START  32'H1C000000
`define INST_MEM_DEPTH  16
`define INST_MEM_FILE   "mem_init/imem.init"

// data memory size: 2 ^ DATA_MEM_DEPTH * 4B
`define DATA_MEM_START  32'H1C000000
`define DATA_MEM_DEPTH  16
`define DATA_MEM_FILE   "mem_init/dmem.init"

// core type
`define SIMPLE_SINGLE_CYCLE     8'H0
`define COMPLETE_SINGLE_CYCLE   8'H1
`define PIPELINE                8'H2
`define CORE_TYPE               `SIMPLE_SINGLE_CYCLE

// peripheral
`define UART_IO                 1'H0