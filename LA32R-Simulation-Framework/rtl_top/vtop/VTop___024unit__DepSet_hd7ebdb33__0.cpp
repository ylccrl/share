// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop__Syms.h"
#include "VTop__Syms.h"
#include "VTop___024unit.h"

extern "C" void expose_configs(int _instMemStart, int _instMemDepth, const char* _instMemFile, int _dataMemStart, int _dataMemDepth, const char* DataMemFile, char _core, svBit _uartIO);

VL_INLINE_OPT void VTop___024unit____Vdpiimwrap_expose_configs_TOP____024unit(IData/*31:0*/ _instMemStart, IData/*31:0*/ _instMemDepth, std::string _instMemFile, IData/*31:0*/ _dataMemStart, IData/*31:0*/ _dataMemDepth, std::string DataMemFile, CData/*7:0*/ _core, CData/*0:0*/ _uartIO) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VTop___024unit____Vdpiimwrap_expose_configs_TOP____024unit\n"); );
    // Body
    int _instMemStart__Vcvt;
    for (size_t _instMemStart__Vidx = 0; _instMemStart__Vidx < 1; ++_instMemStart__Vidx) _instMemStart__Vcvt = _instMemStart;
    int _instMemDepth__Vcvt;
    for (size_t _instMemDepth__Vidx = 0; _instMemDepth__Vidx < 1; ++_instMemDepth__Vidx) _instMemDepth__Vcvt = _instMemDepth;
    const char* _instMemFile__Vcvt;
    for (size_t _instMemFile__Vidx = 0; _instMemFile__Vidx < 1; ++_instMemFile__Vidx) _instMemFile__Vcvt = _instMemFile.c_str();
    int _dataMemStart__Vcvt;
    for (size_t _dataMemStart__Vidx = 0; _dataMemStart__Vidx < 1; ++_dataMemStart__Vidx) _dataMemStart__Vcvt = _dataMemStart;
    int _dataMemDepth__Vcvt;
    for (size_t _dataMemDepth__Vidx = 0; _dataMemDepth__Vidx < 1; ++_dataMemDepth__Vidx) _dataMemDepth__Vcvt = _dataMemDepth;
    const char* DataMemFile__Vcvt;
    for (size_t DataMemFile__Vidx = 0; DataMemFile__Vidx < 1; ++DataMemFile__Vidx) DataMemFile__Vcvt = DataMemFile.c_str();
    char _core__Vcvt;
    for (size_t _core__Vidx = 0; _core__Vidx < 1; ++_core__Vidx) _core__Vcvt = _core;
    svBit _uartIO__Vcvt;
    for (size_t _uartIO__Vidx = 0; _uartIO__Vidx < 1; ++_uartIO__Vidx) _uartIO__Vcvt = _uartIO;
    expose_configs(_instMemStart__Vcvt, _instMemDepth__Vcvt, _instMemFile__Vcvt, _dataMemStart__Vcvt, _dataMemDepth__Vcvt, DataMemFile__Vcvt, _core__Vcvt, _uartIO__Vcvt);
}

extern "C" void expose_memory(int _dataMemDepth, const svLogicVecVal* _mem);

VL_INLINE_OPT void VTop___024unit____Vdpiimwrap_expose_memory_TOP____024unit(IData/*31:0*/ _dataMemDepth, VlUnpacked<IData/*31:0*/, 65536> _mem) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VTop___024unit____Vdpiimwrap_expose_memory_TOP____024unit\n"); );
    // Body
    int _dataMemDepth__Vcvt;
    for (size_t _dataMemDepth__Vidx = 0; _dataMemDepth__Vidx < 1; ++_dataMemDepth__Vidx) _dataMemDepth__Vcvt = _dataMemDepth;
    svLogicVecVal _mem__Vcvt[65536];
    for (size_t _mem__Vidx = 0; _mem__Vidx < 65536; ++_mem__Vidx) VL_SET_SVLV_I(32, _mem__Vcvt + 1 * _mem__Vidx, (&_mem[0])[_mem__Vidx]);
    expose_memory(_dataMemDepth__Vcvt, _mem__Vcvt);
}
