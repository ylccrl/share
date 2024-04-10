// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop__Syms.h"
#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_initial__TOP(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    VTop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/top.v", 6, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->uart_wdata = (0xffU & vlSelf->Top__DOT__cpu_dmem_wdata);
    vlSelf->commit = vlSelf->Top__DOT__cpu__DOT__commit_reg;
    vlSelf->commit_halt = vlSelf->Top__DOT__cpu__DOT__commit_halt_reg;
    vlSelf->commit_pc = vlSelf->Top__DOT__cpu__DOT__commit_pc_reg;
    vlSelf->commit_inst = vlSelf->Top__DOT__cpu__DOT__commit_inst_reg;
    vlSelf->commit_reg_we = vlSelf->Top__DOT__cpu__DOT__commit_reg_we_reg;
    vlSelf->commit_reg_wa = vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg;
    vlSelf->commit_reg_wd = vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg;
    vlSelf->commit_dmem_we = vlSelf->Top__DOT__cpu__DOT__commit_dmem_we_reg;
    vlSelf->commit_dmem_wa = (0xffffU & (vlSelf->Top__DOT__cpu__DOT__commit_dmem_wa_reg 
                                         >> 2U));
    vlSelf->commit_dmem_wd = vlSelf->Top__DOT__cpu__DOT__commit_dmem_wd_reg;
    vlSelf->uart_we = ((0xa00003f0U == vlSelf->Top__DOT__cpu_dmem_addr) 
                       & (IData)(vlSelf->Top__DOT__cpu_dmem_we));
    vlSelf->uart_consumed = ((0xa00003fcU == vlSelf->Top__DOT__cpu_dmem_addr) 
                             & (IData)(vlSelf->Top__DOT__cpu_dmem_we));
    vlSelf->debug_reg_rd = vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
        [vlSelf->debug_reg_ra];
    vlSelf->Top__DOT__inst = vlSelf->Top__DOT__inst_mem__DOT__mem
        [(0xffffU & (vlSelf->Top__DOT__cpu__DOT__cur_pc 
                     >> 2U))];
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t = 0U;
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 0U;
    if ((0x10000000U <= vlSelf->Top__DOT__inst)) {
        if ((0xeU == (vlSelf->Top__DOT__inst >> 0x19U))) {
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                = (0x1fU & vlSelf->Top__DOT__inst);
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0U;
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                = (0xfffff000U & (vlSelf->Top__DOT__inst 
                                  << 7U));
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t = 1U;
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
        } else if ((0xaU == (vlSelf->Top__DOT__inst 
                             >> 0x19U))) {
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                = (0x1fU & vlSelf->Top__DOT__inst);
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0U;
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                = (0xfffff000U & (vlSelf->Top__DOT__inst 
                                  << 7U));
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
        }
        if ((0xeU != (vlSelf->Top__DOT__inst >> 0x19U))) {
            if ((0xaU != (vlSelf->Top__DOT__inst >> 0x19U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t = 0U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t = 0U;
            }
        }
    } else {
        if (((0x10000000U > vlSelf->Top__DOT__inst) 
             & (0x2000000U <= vlSelf->Top__DOT__inst))) {
            if ((0xfU == (vlSelf->Top__DOT__inst >> 0x16U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xbU;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (0xfffU & (vlSelf->Top__DOT__inst 
                                 >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((0xeU == (vlSelf->Top__DOT__inst 
                                 >> 0x16U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xaU;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (0xfffU & (vlSelf->Top__DOT__inst 
                                 >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((0xdU == (vlSelf->Top__DOT__inst 
                                 >> 0x16U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 9U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (0xfffU & (vlSelf->Top__DOT__inst 
                                 >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((0xaU == (vlSelf->Top__DOT__inst 
                                 >> 0x16U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (((- (IData)((1U & (vlSelf->Top__DOT__inst 
                                          >> 0x15U)))) 
                        << 0xcU) | (0xfffU & (vlSelf->Top__DOT__inst 
                                              >> 0xaU)));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((9U == (vlSelf->Top__DOT__inst 
                               >> 0x16U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 5U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (((- (IData)((1U & (vlSelf->Top__DOT__inst 
                                          >> 0x15U)))) 
                        << 0xcU) | (0xfffU & (vlSelf->Top__DOT__inst 
                                              >> 0xaU)));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((8U == (vlSelf->Top__DOT__inst 
                               >> 0x16U))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 4U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (((- (IData)((1U & (vlSelf->Top__DOT__inst 
                                          >> 0x15U)))) 
                        << 0xcU) | (0xfffU & (vlSelf->Top__DOT__inst 
                                              >> 0xaU)));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            }
            if ((0xfU != (vlSelf->Top__DOT__inst >> 0x16U))) {
                if ((0xeU != (vlSelf->Top__DOT__inst 
                              >> 0x16U))) {
                    if ((0xdU != (vlSelf->Top__DOT__inst 
                                  >> 0x16U))) {
                        if ((0xaU != (vlSelf->Top__DOT__inst 
                                      >> 0x16U))) {
                            if ((9U != (vlSelf->Top__DOT__inst 
                                        >> 0x16U))) {
                                if ((8U != (vlSelf->Top__DOT__inst 
                                            >> 0x16U))) {
                                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t = 0U;
                                }
                            }
                        }
                    }
                }
            }
        } else if (((0x2000000U > vlSelf->Top__DOT__inst) 
                    & (0x400000U <= vlSelf->Top__DOT__inst))) {
            if ((0x91U == (vlSelf->Top__DOT__inst >> 0xfU))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0x10U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((0x89U == (vlSelf->Top__DOT__inst 
                                  >> 0xfU))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xfU;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            } else if ((0x81U == (vlSelf->Top__DOT__inst 
                                  >> 0xfU))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = 1U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xeU;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 1U;
            }
            if ((0x91U != (vlSelf->Top__DOT__inst >> 0xfU))) {
                if ((0x89U != (vlSelf->Top__DOT__inst 
                               >> 0xfU))) {
                    if ((0x81U != (vlSelf->Top__DOT__inst 
                                   >> 0xfU))) {
                        vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t = 0U;
                    }
                }
            }
        } else if (((0x400000U > vlSelf->Top__DOT__inst) 
                    & (0x100000U <= vlSelf->Top__DOT__inst))) {
            if (((((((((0x30U == (vlSelf->Top__DOT__inst 
                                  >> 0xfU)) | (0x2fU 
                                               == (vlSelf->Top__DOT__inst 
                                                   >> 0xfU))) 
                      | (0x2eU == (vlSelf->Top__DOT__inst 
                                   >> 0xfU))) | (0x2bU 
                                                 == 
                                                 (vlSelf->Top__DOT__inst 
                                                  >> 0xfU))) 
                    | (0x2aU == (vlSelf->Top__DOT__inst 
                                 >> 0xfU))) | (0x29U 
                                               == (vlSelf->Top__DOT__inst 
                                                   >> 0xfU))) 
                  | (0x25U == (vlSelf->Top__DOT__inst 
                               >> 0xfU))) | (0x24U 
                                             == (vlSelf->Top__DOT__inst 
                                                 >> 0xfU)))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                if ((0x30U == (vlSelf->Top__DOT__inst 
                               >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0x10U;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else if ((0x2fU == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xfU;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else if ((0x2eU == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xeU;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else if ((0x2bU == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xbU;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else if ((0x2aU == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0xaU;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else if ((0x29U == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 9U;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else if ((0x25U == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 5U;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 4U;
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                }
            } else if ((0x22U == (vlSelf->Top__DOT__inst 
                                  >> 0xfU))) {
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                    = (0x1fU & vlSelf->Top__DOT__inst);
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 2U;
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 0xaU));
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                    = (0x1fU & (vlSelf->Top__DOT__inst 
                                >> 5U));
            } else {
                if ((0x25U == (vlSelf->Top__DOT__inst 
                               >> 0xfU))) {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                        = (0x1fU & vlSelf->Top__DOT__inst);
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 0xaU));
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & (vlSelf->Top__DOT__inst 
                                    >> 5U));
                } else {
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t 
                        = (0x1fU & 0U);
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t 
                        = (0x1fU & 0U);
                    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t 
                        = (0x1fU & 0U);
                }
                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = 0U;
            }
            vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t 
                = (((((((((0x30U == (vlSelf->Top__DOT__inst 
                                     >> 0xfU)) | (0x2fU 
                                                  == 
                                                  (vlSelf->Top__DOT__inst 
                                                   >> 0xfU))) 
                         | (0x2eU == (vlSelf->Top__DOT__inst 
                                      >> 0xfU))) | 
                        (0x2bU == (vlSelf->Top__DOT__inst 
                                   >> 0xfU))) | (0x2aU 
                                                 == 
                                                 (vlSelf->Top__DOT__inst 
                                                  >> 0xfU))) 
                      | (0x29U == (vlSelf->Top__DOT__inst 
                                   >> 0xfU))) | (0x25U 
                                                 == 
                                                 (vlSelf->Top__DOT__inst 
                                                  >> 0xfU))) 
                    | (0x24U == (vlSelf->Top__DOT__inst 
                                 >> 0xfU))) | ((0x22U 
                                                == 
                                                (vlSelf->Top__DOT__inst 
                                                 >> 0xfU)) 
                                               | (0x25U 
                                                  == 
                                                  (vlSelf->Top__DOT__inst 
                                                   >> 0xfU))));
            if ((1U & (~ ((((((((0x30U == (vlSelf->Top__DOT__inst 
                                           >> 0xfU)) 
                                | (0x2fU == (vlSelf->Top__DOT__inst 
                                             >> 0xfU))) 
                               | (0x2eU == (vlSelf->Top__DOT__inst 
                                            >> 0xfU))) 
                              | (0x2bU == (vlSelf->Top__DOT__inst 
                                           >> 0xfU))) 
                             | (0x2aU == (vlSelf->Top__DOT__inst 
                                          >> 0xfU))) 
                            | (0x29U == (vlSelf->Top__DOT__inst 
                                         >> 0xfU))) 
                           | (0x25U == (vlSelf->Top__DOT__inst 
                                        >> 0xfU))) 
                          | (0x24U == (vlSelf->Top__DOT__inst 
                                       >> 0xfU)))))) {
                if ((0x22U != (vlSelf->Top__DOT__inst 
                               >> 0xfU))) {
                    if ((0x25U != (vlSelf->Top__DOT__inst 
                                   >> 0xfU))) {
                        vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t = 0U;
                        vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = 0U;
                    }
                }
            }
        }
        if ((1U & (~ ((0x10000000U > vlSelf->Top__DOT__inst) 
                      & (0x2000000U <= vlSelf->Top__DOT__inst))))) {
            if ((1U & (~ ((0x2000000U > vlSelf->Top__DOT__inst) 
                          & (0x400000U <= vlSelf->Top__DOT__inst))))) {
                if (((0x400000U > vlSelf->Top__DOT__inst) 
                     & (0x100000U <= vlSelf->Top__DOT__inst))) {
                    if ((1U & (~ ((((((((0x30U == (vlSelf->Top__DOT__inst 
                                                   >> 0xfU)) 
                                        | (0x2fU == 
                                           (vlSelf->Top__DOT__inst 
                                            >> 0xfU))) 
                                       | (0x2eU == 
                                          (vlSelf->Top__DOT__inst 
                                           >> 0xfU))) 
                                      | (0x2bU == (vlSelf->Top__DOT__inst 
                                                   >> 0xfU))) 
                                     | (0x2aU == (vlSelf->Top__DOT__inst 
                                                  >> 0xfU))) 
                                    | (0x29U == (vlSelf->Top__DOT__inst 
                                                 >> 0xfU))) 
                                   | (0x25U == (vlSelf->Top__DOT__inst 
                                                >> 0xfU))) 
                                  | (0x24U == (vlSelf->Top__DOT__inst 
                                               >> 0xfU)))))) {
                        if ((0x22U != (vlSelf->Top__DOT__inst 
                                       >> 0xfU))) {
                            if ((0x25U != (vlSelf->Top__DOT__inst 
                                           >> 0xfU))) {
                                vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->Top__DOT__cpu__DOT__alu_src0 = ((IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t)
                                             ? vlSelf->Top__DOT__cpu__DOT__cur_pc
                                             : vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
                                            [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t]);
    vlSelf->Top__DOT__cpu__DOT__alu_src1 = ((IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t)
                                             ? vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t
                                             : vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
                                            [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t]);
    vlSelf->Top__DOT__cpu__DOT__rf_wd = ((0x10U & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                          ? ((8U & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                              ? 0U : 
                                             ((4U & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                               ? 0U
                                               : ((2U 
                                                   & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 0U
                                                    : vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? vlSelf->Top__DOT__cpu__DOT__alu_src0
                                                    : 
                                                   ((0x1fU 
                                                     >= vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,32, vlSelf->Top__DOT__cpu__DOT__alu_src0, vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     : 
                                                    (- 
                                                     (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                      >> 0x1fU)))))))
                                          : ((8U & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                              ? ((4U 
                                                  & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 
                                                   ((0x1fU 
                                                     >= vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     ? 
                                                    (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                     >> vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     : 0U)
                                                    : 
                                                   ((0x1fU 
                                                     >= vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     ? 
                                                    (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                     << vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     : 0U))
                                                   : 0U)
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 
                                                   (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                    ^ vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                    : 
                                                   (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                    | vlSelf->Top__DOT__cpu__DOT__alu_src1))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 
                                                   (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                    & vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                    : 0U)))
                                              : ((4U 
                                                  & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 
                                                   ((vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                     < vlSelf->Top__DOT__cpu__DOT__alu_src1)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   (((vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                      >> 0x1fU) 
                                                     > 
                                                     (vlSelf->Top__DOT__cpu__DOT__alu_src1 
                                                      >> 0x1fU))
                                                     ? 1U
                                                     : 
                                                    (((vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                       >> 0x1fU) 
                                                      < 
                                                      (vlSelf->Top__DOT__cpu__DOT__alu_src1 
                                                       >> 0x1fU))
                                                      ? 0U
                                                      : 
                                                     ((vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                       < 
                                                       (- vlSelf->Top__DOT__cpu__DOT__alu_src1))
                                                       ? 1U
                                                       : 0U)))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                    - vlSelf->Top__DOT__cpu__DOT__alu_src1))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Top__DOT__cpu__DOT__alu_src0 
                                                    + vlSelf->Top__DOT__cpu__DOT__alu_src1))))));
}

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->uart_we = VL_RAND_RESET_I(1);
    vlSelf->uart_wdata = VL_RAND_RESET_I(8);
    vlSelf->uart_ready = VL_RAND_RESET_I(1);
    vlSelf->uart_rdata = VL_RAND_RESET_I(8);
    vlSelf->uart_consumed = VL_RAND_RESET_I(1);
    vlSelf->commit = VL_RAND_RESET_I(1);
    vlSelf->commit_halt = VL_RAND_RESET_I(1);
    vlSelf->commit_pc = VL_RAND_RESET_I(32);
    vlSelf->commit_inst = VL_RAND_RESET_I(32);
    vlSelf->commit_reg_we = VL_RAND_RESET_I(1);
    vlSelf->commit_reg_wa = VL_RAND_RESET_I(5);
    vlSelf->commit_reg_wd = VL_RAND_RESET_I(32);
    vlSelf->commit_dmem_we = VL_RAND_RESET_I(1);
    vlSelf->commit_dmem_wa = VL_RAND_RESET_I(16);
    vlSelf->commit_dmem_wd = VL_RAND_RESET_I(32);
    vlSelf->debug_reg_ra = VL_RAND_RESET_I(5);
    vlSelf->debug_reg_rd = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu_dmem_addr = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu_dmem_wdata = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu_dmem_we = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__cur_pc = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__rf_wd = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__alu_src0 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__alu_src1 = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__cur_npc_t = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__commit_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__commit_pc_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__commit_inst_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__commit_halt_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__commit_reg_we_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__commit_dmem_we_reg = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__commit_dmem_wa_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__commit_dmem_wd_reg = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t = VL_RAND_RESET_I(5);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->Top__DOT__inst_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->Top__DOT__data_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
