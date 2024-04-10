// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTop__Syms.h"
#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->debug_reg_rd = vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
        [vlSelf->debug_reg_ra];
}

void VTop___024root___eval_ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0;
    __Vdlyvdim0__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0;
    __Vdlyvval__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0 = 0;
    SData/*15:0*/ __Vdlyvdim0__Top__DOT__data_mem__DOT__mem__v0;
    __Vdlyvdim0__Top__DOT__data_mem__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__Top__DOT__data_mem__DOT__mem__v0;
    __Vdlyvval__Top__DOT__data_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__data_mem__DOT__mem__v0;
    __Vdlyvset__Top__DOT__data_mem__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__Top__DOT__data_mem__DOT__mem__v0 = 0U;
    if (((0xa00003f0U != (0xfffffff0U & vlSelf->Top__DOT__cpu_dmem_addr)) 
         & (IData)(vlSelf->Top__DOT__cpu_dmem_we))) {
        __Vdlyvval__Top__DOT__data_mem__DOT__mem__v0 
            = vlSelf->Top__DOT__cpu_dmem_wdata;
        __Vdlyvset__Top__DOT__data_mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__Top__DOT__data_mem__DOT__mem__v0 
            = (0xffffU & (vlSelf->Top__DOT__cpu_dmem_addr 
                          >> 2U));
    }
    __Vdlyvval__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0 
        = ((IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t)
            ? ((0U != (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t))
                ? vlSelf->Top__DOT__cpu__DOT__rf_wd
                : 0U) : vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
           [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t]);
    __Vdlyvdim0__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0 
        = vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t;
    vlSelf->Top__DOT__cpu__DOT__commit_dmem_wd_reg = 0U;
    vlSelf->Top__DOT__cpu__DOT__commit_dmem_wa_reg = 0U;
    vlSelf->Top__DOT__cpu__DOT__commit_dmem_we_reg = 0U;
    vlSelf->Top__DOT__cpu__DOT__commit_reg = (1U & 
                                              (~ (IData)(vlSelf->rst)));
    if (vlSelf->rst) {
        vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg = 0U;
        vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg = 0U;
        vlSelf->Top__DOT__cpu__DOT__commit_inst_reg = 0U;
        vlSelf->Top__DOT__cpu__DOT__commit_pc_reg = 0U;
        vlSelf->Top__DOT__cpu__DOT__cur_pc = 0x1c000000U;
    } else {
        vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg 
            = vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t;
        vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg 
            = vlSelf->Top__DOT__cpu__DOT__rf_wd;
        vlSelf->Top__DOT__cpu__DOT__commit_inst_reg 
            = vlSelf->Top__DOT__inst;
        vlSelf->Top__DOT__cpu__DOT__commit_pc_reg = vlSelf->Top__DOT__cpu__DOT__cur_pc;
        vlSelf->Top__DOT__cpu__DOT__cur_pc = vlSelf->Top__DOT__cpu__DOT__cur_npc_t;
    }
    vlSelf->Top__DOT__cpu__DOT__commit_reg_we_reg = 
        ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t));
    vlSelf->Top__DOT__cpu__DOT__commit_halt_reg = (
                                                   (~ (IData)(vlSelf->rst)) 
                                                   & (0x80000000U 
                                                      == vlSelf->Top__DOT__inst));
    if (__Vdlyvset__Top__DOT__data_mem__DOT__mem__v0) {
        vlSelf->Top__DOT__data_mem__DOT__mem[__Vdlyvdim0__Top__DOT__data_mem__DOT__mem__v0] 
            = __Vdlyvval__Top__DOT__data_mem__DOT__mem__v0;
    }
    vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[__Vdlyvdim0__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0] 
        = __Vdlyvval__Top__DOT__cpu__DOT__my_regfile__DOT__reg_file__v0;
    vlSelf->debug_reg_rd = vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
        [vlSelf->debug_reg_ra];
    vlSelf->commit_dmem_wd = vlSelf->Top__DOT__cpu__DOT__commit_dmem_wd_reg;
    vlSelf->commit_dmem_wa = (0xffffU & (vlSelf->Top__DOT__cpu__DOT__commit_dmem_wa_reg 
                                         >> 2U));
    vlSelf->commit_dmem_we = vlSelf->Top__DOT__cpu__DOT__commit_dmem_we_reg;
    vlSelf->commit = vlSelf->Top__DOT__cpu__DOT__commit_reg;
    vlSelf->commit_reg_wa = vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg;
    vlSelf->commit_reg_we = vlSelf->Top__DOT__cpu__DOT__commit_reg_we_reg;
    vlSelf->commit_reg_wd = vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg;
    vlSelf->commit_inst = vlSelf->Top__DOT__cpu__DOT__commit_inst_reg;
    vlSelf->commit_halt = vlSelf->Top__DOT__cpu__DOT__commit_halt_reg;
    vlSelf->commit_pc = vlSelf->Top__DOT__cpu__DOT__commit_pc_reg;
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

void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf);

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG
void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VTop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/top.v", 6, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VTop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VTop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/top.v", 6, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VTop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/top.v", 6, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->uart_ready & 0xfeU))) {
        Verilated::overWidthError("uart_ready");}
    if (VL_UNLIKELY((vlSelf->debug_reg_ra & 0xe0U))) {
        Verilated::overWidthError("debug_reg_ra");}
}
#endif  // VL_DEBUG
