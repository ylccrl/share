// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class VTop___024unit;


class VTop__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTop___024root final : public VerilatedModule {
  public:
    // CELLS
    VTop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(uart_we,0,0);
    VL_OUT8(uart_wdata,7,0);
    VL_IN8(uart_ready,0,0);
    VL_IN8(uart_rdata,7,0);
    VL_OUT8(uart_consumed,0,0);
    VL_OUT8(commit,0,0);
    VL_OUT8(commit_halt,0,0);
    VL_OUT8(commit_reg_we,0,0);
    VL_OUT8(commit_reg_wa,4,0);
    VL_OUT8(commit_dmem_we,0,0);
    VL_IN8(debug_reg_ra,4,0);
    CData/*0:0*/ Top__DOT__cpu_dmem_we;
    CData/*0:0*/ Top__DOT__cpu__DOT__commit_reg;
    CData/*0:0*/ Top__DOT__cpu__DOT__commit_halt_reg;
    CData/*0:0*/ Top__DOT__cpu__DOT__commit_reg_we_reg;
    CData/*4:0*/ Top__DOT__cpu__DOT__commit_reg_wa_reg;
    CData/*0:0*/ Top__DOT__cpu__DOT__commit_dmem_we_reg;
    CData/*4:0*/ Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t;
    CData/*4:0*/ Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t;
    CData/*4:0*/ Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t;
    CData/*4:0*/ Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t;
    CData/*0:0*/ Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t;
    CData/*0:0*/ Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t;
    CData/*0:0*/ Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(commit_dmem_wa,15,0);
    VL_OUT(commit_pc,31,0);
    VL_OUT(commit_inst,31,0);
    VL_OUT(commit_reg_wd,31,0);
    VL_OUT(commit_dmem_wd,31,0);
    VL_OUT(debug_reg_rd,31,0);
    IData/*31:0*/ Top__DOT__inst;
    IData/*31:0*/ Top__DOT__cpu_dmem_addr;
    IData/*31:0*/ Top__DOT__cpu_dmem_wdata;
    IData/*31:0*/ Top__DOT__cpu__DOT__cur_pc;
    IData/*31:0*/ Top__DOT__cpu__DOT__rf_wd;
    IData/*31:0*/ Top__DOT__cpu__DOT__alu_src0;
    IData/*31:0*/ Top__DOT__cpu__DOT__alu_src1;
    IData/*31:0*/ Top__DOT__cpu__DOT__cur_npc_t;
    IData/*31:0*/ Top__DOT__cpu__DOT__commit_pc_reg;
    IData/*31:0*/ Top__DOT__cpu__DOT__commit_inst_reg;
    IData/*31:0*/ Top__DOT__cpu__DOT__commit_reg_wd_reg;
    IData/*31:0*/ Top__DOT__cpu__DOT__commit_dmem_wa_reg;
    IData/*31:0*/ Top__DOT__cpu__DOT__commit_dmem_wd_reg;
    IData/*31:0*/ Top__DOT__cpu__DOT__my_decode__DOT__imm_t;
    IData/*31:0*/ Top__DOT__cpu__DOT__my_regfile__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> Top__DOT__cpu__DOT__my_regfile__DOT__reg_file;
    VlUnpacked<IData/*31:0*/, 65536> Top__DOT__inst_mem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 65536> Top__DOT__data_mem__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
