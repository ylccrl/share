// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__trace_chg_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_top_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTop___024root__trace_chg_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(vlSelf->Top__DOT__cpu__DOT__cur_pc),32);
        bufp->chgIData(oldp+2,(vlSelf->Top__DOT__inst),32);
        bufp->chgIData(oldp+3,(vlSelf->Top__DOT__data_mem__DOT__mem
                               [(0xffffU & (vlSelf->Top__DOT__cpu_dmem_addr 
                                            >> 2U))]),32);
        bufp->chgIData(oldp+4,(vlSelf->Top__DOT__cpu__DOT__commit_dmem_wa_reg),32);
        bufp->chgIData(oldp+5,(((IData)(4U) + vlSelf->Top__DOT__cpu__DOT__cur_pc)),32);
        bufp->chgIData(oldp+6,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t),32);
        bufp->chgIData(oldp+7,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
                               [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t]),32);
        bufp->chgIData(oldp+8,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
                               [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t]),32);
        bufp->chgIData(oldp+9,(vlSelf->Top__DOT__cpu__DOT__rf_wd),32);
        bufp->chgIData(oldp+10,(vlSelf->Top__DOT__cpu__DOT__alu_src0),32);
        bufp->chgIData(oldp+11,(vlSelf->Top__DOT__cpu__DOT__alu_src1),32);
        bufp->chgBit(oldp+12,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t));
        bufp->chgBit(oldp+13,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t));
        bufp->chgBit(oldp+14,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t));
        bufp->chgCData(oldp+15,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t),5);
        bufp->chgCData(oldp+16,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t),5);
        bufp->chgCData(oldp+17,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t),5);
        bufp->chgCData(oldp+18,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t),5);
        bufp->chgBit(oldp+19,(vlSelf->Top__DOT__cpu__DOT__commit_reg));
        bufp->chgIData(oldp+20,(vlSelf->Top__DOT__cpu__DOT__commit_pc_reg),32);
        bufp->chgIData(oldp+21,(vlSelf->Top__DOT__cpu__DOT__commit_inst_reg),32);
        bufp->chgBit(oldp+22,(vlSelf->Top__DOT__cpu__DOT__commit_halt_reg));
        bufp->chgBit(oldp+23,(vlSelf->Top__DOT__cpu__DOT__commit_reg_we_reg));
        bufp->chgCData(oldp+24,(vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg),5);
        bufp->chgIData(oldp+25,(vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg),32);
        bufp->chgBit(oldp+26,(vlSelf->Top__DOT__cpu__DOT__commit_dmem_we_reg));
        bufp->chgIData(oldp+27,(vlSelf->Top__DOT__cpu__DOT__commit_dmem_wd_reg),32);
        bufp->chgIData(oldp+28,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0]),32);
        bufp->chgIData(oldp+29,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[1]),32);
        bufp->chgIData(oldp+30,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[2]),32);
        bufp->chgIData(oldp+31,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[3]),32);
        bufp->chgIData(oldp+32,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[4]),32);
        bufp->chgIData(oldp+33,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[5]),32);
        bufp->chgIData(oldp+34,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[6]),32);
        bufp->chgIData(oldp+35,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[7]),32);
        bufp->chgIData(oldp+36,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[8]),32);
        bufp->chgIData(oldp+37,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[9]),32);
        bufp->chgIData(oldp+38,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[10]),32);
        bufp->chgIData(oldp+39,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[11]),32);
        bufp->chgIData(oldp+40,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[12]),32);
        bufp->chgIData(oldp+41,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[13]),32);
        bufp->chgIData(oldp+42,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[14]),32);
        bufp->chgIData(oldp+43,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[15]),32);
        bufp->chgIData(oldp+44,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[16]),32);
        bufp->chgIData(oldp+45,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[17]),32);
        bufp->chgIData(oldp+46,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[18]),32);
        bufp->chgIData(oldp+47,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[19]),32);
        bufp->chgIData(oldp+48,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[20]),32);
        bufp->chgIData(oldp+49,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[21]),32);
        bufp->chgIData(oldp+50,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[22]),32);
        bufp->chgIData(oldp+51,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[23]),32);
        bufp->chgIData(oldp+52,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[24]),32);
        bufp->chgIData(oldp+53,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[25]),32);
        bufp->chgIData(oldp+54,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[26]),32);
        bufp->chgIData(oldp+55,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[27]),32);
        bufp->chgIData(oldp+56,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[28]),32);
        bufp->chgIData(oldp+57,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[29]),32);
        bufp->chgIData(oldp+58,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[30]),32);
        bufp->chgIData(oldp+59,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[31]),32);
        bufp->chgSData(oldp+60,((0xffffU & (vlSelf->Top__DOT__cpu__DOT__cur_pc 
                                            >> 2U))),16);
    }
    bufp->chgBit(oldp+61,(vlSelf->clk));
    bufp->chgBit(oldp+62,(vlSelf->rst));
    bufp->chgBit(oldp+63,(vlSelf->uart_we));
    bufp->chgCData(oldp+64,(vlSelf->uart_wdata),8);
    bufp->chgBit(oldp+65,(vlSelf->uart_ready));
    bufp->chgCData(oldp+66,(vlSelf->uart_rdata),8);
    bufp->chgBit(oldp+67,(vlSelf->uart_consumed));
    bufp->chgBit(oldp+68,(vlSelf->commit));
    bufp->chgBit(oldp+69,(vlSelf->commit_halt));
    bufp->chgIData(oldp+70,(vlSelf->commit_pc),32);
    bufp->chgIData(oldp+71,(vlSelf->commit_inst),32);
    bufp->chgBit(oldp+72,(vlSelf->commit_reg_we));
    bufp->chgCData(oldp+73,(vlSelf->commit_reg_wa),5);
    bufp->chgIData(oldp+74,(vlSelf->commit_reg_wd),32);
    bufp->chgBit(oldp+75,(vlSelf->commit_dmem_we));
    bufp->chgSData(oldp+76,(vlSelf->commit_dmem_wa),16);
    bufp->chgIData(oldp+77,(vlSelf->commit_dmem_wd),32);
    bufp->chgCData(oldp+78,(vlSelf->debug_reg_ra),5);
    bufp->chgIData(oldp+79,(vlSelf->debug_reg_rd),32);
    bufp->chgIData(oldp+80,(((0xa00003f4U == vlSelf->Top__DOT__cpu_dmem_addr)
                              ? (IData)(vlSelf->uart_rdata)
                              : ((0xa00003f8U == vlSelf->Top__DOT__cpu_dmem_addr)
                                  ? (IData)(vlSelf->uart_ready)
                                  : vlSelf->Top__DOT__data_mem__DOT__mem
                                 [(0xffffU & (vlSelf->Top__DOT__cpu_dmem_addr 
                                              >> 2U))]))),32);
}

void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_cleanup\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
