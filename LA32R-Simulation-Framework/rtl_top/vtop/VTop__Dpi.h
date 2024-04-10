// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/top.v:3:30
    extern void expose_configs(int _instMemStart, int _instMemDepth, const char* _instMemFile, int _dataMemStart, int _dataMemDepth, const char* DataMemFile, char _core, svBit _uartIO);
    // DPI import at /home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/mem_ip_sim/data_mem.v:3:30
    extern void expose_memory(int _dataMemDepth, const svLogicVecVal* _mem);

#ifdef __cplusplus
}
#endif

#endif  // guard
