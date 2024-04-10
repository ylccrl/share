// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop__Syms.h"
#include "VTop__Syms.h"
#include "VTop___024root.h"

void VTop___024unit____Vdpiimwrap_expose_configs_TOP____024unit(IData/*31:0*/ _instMemStart, IData/*31:0*/ _instMemDepth, std::string _instMemFile, IData/*31:0*/ _dataMemStart, IData/*31:0*/ _dataMemDepth, std::string DataMemFile, CData/*7:0*/ _core, CData/*0:0*/ _uartIO);

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_hbfab386e__0;
    VlWide<5>/*159:0*/ __Vtemp_hbf8fb747__0;
    // Body
    VTop___024unit____Vdpiimwrap_expose_configs_TOP____024unit(0x1c000000U, 0x10U, 
                                                               std::string{"mem_init/imem.init"}, 0x1c000000U, 0x10U, 
                                                               std::string{"mem_init/dmem.init"}, 0U, 0U);
    vlSelf->Top__DOT__cpu__DOT__cur_pc = 0x1c000000U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[1U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[2U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[3U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[4U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[5U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[6U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[7U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[8U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[9U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0xaU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0xbU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0xcU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0xdU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0xeU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0xfU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x10U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x11U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x12U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x13U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x14U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x15U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x16U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x17U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x18U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x19U] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x1aU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x1bU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x1cU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x1dU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x1eU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0x1fU] = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__i = 0x20U;
    __Vtemp_hbfab386e__0[0U] = 0x696e6974U;
    __Vtemp_hbfab386e__0[1U] = 0x6d656d2eU;
    __Vtemp_hbfab386e__0[2U] = 0x69742f69U;
    __Vtemp_hbfab386e__0[3U] = 0x6d5f696eU;
    __Vtemp_hbfab386e__0[4U] = 0x6d65U;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hbfab386e__0)
                 ,  &(vlSelf->Top__DOT__inst_mem__DOT__mem)
                 , 0, ~0ULL);
    __Vtemp_hbf8fb747__0[0U] = 0x696e6974U;
    __Vtemp_hbf8fb747__0[1U] = 0x6d656d2eU;
    __Vtemp_hbf8fb747__0[2U] = 0x69742f64U;
    __Vtemp_hbf8fb747__0[3U] = 0x6d5f696eU;
    __Vtemp_hbf8fb747__0[4U] = 0x6d65U;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_hbf8fb747__0)
                 ,  &(vlSelf->Top__DOT__data_mem__DOT__mem)
                 , 0, ~0ULL);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (0U == vlSelf->__VstlIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
