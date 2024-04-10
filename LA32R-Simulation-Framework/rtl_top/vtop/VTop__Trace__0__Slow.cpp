// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


VL_ATTR_COLD void VTop___024root__trace_init_sub__TOP__0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+62,"clk", false,-1, 0,0);
    tracep->declBus(c+63,"rst", false,-1, 0,0);
    tracep->declBus(c+64,"uart_we", false,-1, 0,0);
    tracep->declBus(c+65,"uart_wdata", false,-1, 7,0);
    tracep->declBus(c+66,"uart_ready", false,-1, 0,0);
    tracep->declBus(c+67,"uart_rdata", false,-1, 7,0);
    tracep->declBus(c+68,"uart_consumed", false,-1, 0,0);
    tracep->declBus(c+69,"commit", false,-1, 0,0);
    tracep->declBus(c+70,"commit_halt", false,-1, 0,0);
    tracep->declBus(c+71,"commit_pc", false,-1, 31,0);
    tracep->declBus(c+72,"commit_inst", false,-1, 31,0);
    tracep->declBus(c+73,"commit_reg_we", false,-1, 0,0);
    tracep->declBus(c+74,"commit_reg_wa", false,-1, 4,0);
    tracep->declBus(c+75,"commit_reg_wd", false,-1, 31,0);
    tracep->declBus(c+76,"commit_dmem_we", false,-1, 0,0);
    tracep->declBus(c+77,"commit_dmem_wa", false,-1, 15,0);
    tracep->declBus(c+78,"commit_dmem_wd", false,-1, 31,0);
    tracep->declBus(c+79,"debug_reg_ra", false,-1, 4,0);
    tracep->declBus(c+80,"debug_reg_rd", false,-1, 31,0);
    tracep->pushNamePrefix("Top ");
    tracep->declBus(c+62,"clk", false,-1, 0,0);
    tracep->declBus(c+63,"rst", false,-1, 0,0);
    tracep->declBus(c+64,"uart_we", false,-1, 0,0);
    tracep->declBus(c+65,"uart_wdata", false,-1, 7,0);
    tracep->declBus(c+66,"uart_ready", false,-1, 0,0);
    tracep->declBus(c+67,"uart_rdata", false,-1, 7,0);
    tracep->declBus(c+68,"uart_consumed", false,-1, 0,0);
    tracep->declBus(c+69,"commit", false,-1, 0,0);
    tracep->declBus(c+70,"commit_halt", false,-1, 0,0);
    tracep->declBus(c+71,"commit_pc", false,-1, 31,0);
    tracep->declBus(c+72,"commit_inst", false,-1, 31,0);
    tracep->declBus(c+73,"commit_reg_we", false,-1, 0,0);
    tracep->declBus(c+74,"commit_reg_wa", false,-1, 4,0);
    tracep->declBus(c+75,"commit_reg_wd", false,-1, 31,0);
    tracep->declBus(c+76,"commit_dmem_we", false,-1, 0,0);
    tracep->declBus(c+77,"commit_dmem_wa", false,-1, 15,0);
    tracep->declBus(c+78,"commit_dmem_wd", false,-1, 31,0);
    tracep->declBus(c+79,"debug_reg_ra", false,-1, 4,0);
    tracep->declBus(c+80,"debug_reg_rd", false,-1, 31,0);
    tracep->declBus(c+2,"pc", false,-1, 31,0);
    tracep->declBus(c+3,"inst", false,-1, 31,0);
    tracep->declBus(c+82,"dmem_wdata", false,-1, 31,0);
    tracep->declBus(c+4,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+83,"dmem_we", false,-1, 0,0);
    tracep->declBus(c+84,"cpu_dmem_addr", false,-1, 31,0);
    tracep->declBus(c+81,"cpu_dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+82,"cpu_dmem_wdata", false,-1, 31,0);
    tracep->declBus(c+85,"cpu_dmem_we", false,-1, 0,0);
    tracep->declBus(c+5,"cpu_commit_dmem_wa", false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBus(c+62,"clk", false,-1, 0,0);
    tracep->declBus(c+63,"rst", false,-1, 0,0);
    tracep->declBus(c+86,"global_en", false,-1, 0,0);
    tracep->declBus(c+2,"imem_raddr", false,-1, 31,0);
    tracep->declBus(c+3,"imem_rdata", false,-1, 31,0);
    tracep->declBus(c+81,"dmem_rdata", false,-1, 31,0);
    tracep->declBus(c+85,"dmem_we", false,-1, 0,0);
    tracep->declBus(c+84,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+82,"dmem_wdata", false,-1, 31,0);
    tracep->declBus(c+69,"commit", false,-1, 0,0);
    tracep->declBus(c+71,"commit_pc", false,-1, 31,0);
    tracep->declBus(c+72,"commit_inst", false,-1, 31,0);
    tracep->declBus(c+70,"commit_halt", false,-1, 0,0);
    tracep->declBus(c+73,"commit_reg_we", false,-1, 0,0);
    tracep->declBus(c+74,"commit_reg_wa", false,-1, 4,0);
    tracep->declBus(c+75,"commit_reg_wd", false,-1, 31,0);
    tracep->declBus(c+76,"commit_dmem_we", false,-1, 0,0);
    tracep->declBus(c+5,"commit_dmem_wa", false,-1, 31,0);
    tracep->declBus(c+78,"commit_dmem_wd", false,-1, 31,0);
    tracep->declBus(c+79,"debug_reg_ra", false,-1, 4,0);
    tracep->declBus(c+80,"debug_reg_rd", false,-1, 31,0);
    tracep->declBus(c+6,"cur_npc", false,-1, 31,0);
    tracep->declBus(c+2,"cur_pc", false,-1, 31,0);
    tracep->declBus(c+7,"imm", false,-1, 31,0);
    tracep->declBus(c+8,"rf_rd0", false,-1, 31,0);
    tracep->declBus(c+9,"rf_rd1", false,-1, 31,0);
    tracep->declBus(c+10,"rf_wd", false,-1, 31,0);
    tracep->declBus(c+11,"alu_src0", false,-1, 31,0);
    tracep->declBus(c+12,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+13,"rf_we", false,-1, 0,0);
    tracep->declBus(c+14,"alu_src0_sel", false,-1, 0,0);
    tracep->declBus(c+15,"alu_src1_sel", false,-1, 0,0);
    tracep->declBus(c+16,"alu_op", false,-1, 4,0);
    tracep->declBus(c+17,"rf_ra0", false,-1, 4,0);
    tracep->declBus(c+18,"rf_ra1", false,-1, 4,0);
    tracep->declBus(c+19,"rf_wa", false,-1, 4,0);
    tracep->declBus(c+87,"cur_npc_t", false,-1, 31,0);
    tracep->declBus(c+2,"cur_pc_t", false,-1, 31,0);
    tracep->declBus(c+7,"imm_t", false,-1, 31,0);
    tracep->declBus(c+8,"rf_rd0_t", false,-1, 31,0);
    tracep->declBus(c+9,"rf_rd1_t", false,-1, 31,0);
    tracep->declBus(c+10,"rf_wd_t", false,-1, 31,0);
    tracep->declBus(c+11,"alu_src0_t", false,-1, 31,0);
    tracep->declBus(c+12,"alu_src1_t", false,-1, 31,0);
    tracep->declBus(c+16,"alu_op_t", false,-1, 4,0);
    tracep->declBus(c+17,"rf_ra0_t", false,-1, 4,0);
    tracep->declBus(c+18,"rf_ra1_t", false,-1, 4,0);
    tracep->declBus(c+19,"rf_wa_t", false,-1, 4,0);
    tracep->declBus(c+13,"rf_we_t", false,-1, 0,0);
    tracep->declBus(c+14,"alu_src0_sel_t", false,-1, 0,0);
    tracep->declBus(c+15,"alu_src1_sel_t", false,-1, 0,0);
    tracep->declBus(c+20,"commit_reg", false,-1, 0,0);
    tracep->declBus(c+21,"commit_pc_reg", false,-1, 31,0);
    tracep->declBus(c+22,"commit_inst_reg", false,-1, 31,0);
    tracep->declBus(c+23,"commit_halt_reg", false,-1, 0,0);
    tracep->declBus(c+24,"commit_reg_we_reg", false,-1, 0,0);
    tracep->declBus(c+25,"commit_reg_wa_reg", false,-1, 4,0);
    tracep->declBus(c+26,"commit_reg_wd_reg", false,-1, 31,0);
    tracep->declBus(c+27,"commit_dmem_we_reg", false,-1, 0,0);
    tracep->declBus(c+5,"commit_dmem_wa_reg", false,-1, 31,0);
    tracep->declBus(c+28,"commit_dmem_wd_reg", false,-1, 31,0);
    tracep->pushNamePrefix("my_add4 ");
    tracep->declBus(c+2,"pc", false,-1, 31,0);
    tracep->declBus(c+6,"npc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_alu ");
    tracep->declBus(c+11,"alu_src0", false,-1, 31,0);
    tracep->declBus(c+12,"alu_src1", false,-1, 31,0);
    tracep->declBus(c+16,"alu_op", false,-1, 4,0);
    tracep->declBus(c+10,"alu_res", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_decode ");
    tracep->declBus(c+3,"inst", false,-1, 31,0);
    tracep->declBus(c+16,"alu_op", false,-1, 4,0);
    tracep->declBus(c+7,"imm", false,-1, 31,0);
    tracep->declBus(c+17,"rf_ra0", false,-1, 4,0);
    tracep->declBus(c+18,"rf_ra1", false,-1, 4,0);
    tracep->declBus(c+19,"rf_wa", false,-1, 4,0);
    tracep->declBus(c+13,"rf_we", false,-1, 0,0);
    tracep->declBus(c+14,"alu_src0_sel", false,-1, 0,0);
    tracep->declBus(c+15,"alu_src1_sel", false,-1, 0,0);
    tracep->declBus(c+88,"atype_7b", false,-1, 31,0);
    tracep->declBus(c+89,"btype_10b", false,-1, 31,0);
    tracep->declBus(c+90,"ctype_17b", false,-1, 31,0);
    tracep->declBus(c+91,"dtype_17b", false,-1, 31,0);
    tracep->declBus(c+7,"imm_t", false,-1, 31,0);
    tracep->declBus(c+16,"alu_op_t", false,-1, 4,0);
    tracep->declBus(c+17,"rf_ra0_t", false,-1, 4,0);
    tracep->declBus(c+18,"rf_ra1_t", false,-1, 4,0);
    tracep->declBus(c+19,"rf_wa_t", false,-1, 4,0);
    tracep->declBus(c+13,"rf_we_t", false,-1, 0,0);
    tracep->declBus(c+14,"alu_src0_sel_t", false,-1, 0,0);
    tracep->declBus(c+15,"alu_src1_sel_t", false,-1, 0,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_mux0 ");
    tracep->declBus(c+92,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+8,"src0", false,-1, 31,0);
    tracep->declBus(c+2,"src1", false,-1, 31,0);
    tracep->declBus(c+14,"sel", false,-1, 0,0);
    tracep->declBus(c+11,"res", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_mux1 ");
    tracep->declBus(c+92,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"src0", false,-1, 31,0);
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+15,"sel", false,-1, 0,0);
    tracep->declBus(c+12,"res", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_pc ");
    tracep->declBus(c+62,"clk", false,-1, 0,0);
    tracep->declBus(c+63,"rst", false,-1, 0,0);
    tracep->declBus(c+86,"en", false,-1, 0,0);
    tracep->declBus(c+87,"npc", false,-1, 31,0);
    tracep->declBus(c+2,"pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("my_regfile ");
    tracep->declBus(c+62,"clk", false,-1, 0,0);
    tracep->declBus(c+17,"rf_ra0", false,-1, 4,0);
    tracep->declBus(c+18,"rf_ra1", false,-1, 4,0);
    tracep->declBus(c+79,"dbg_reg_ra", false,-1, 4,0);
    tracep->declBus(c+19,"rf_wa", false,-1, 4,0);
    tracep->declBus(c+13,"rf_we", false,-1, 0,0);
    tracep->declBus(c+10,"rf_wd", false,-1, 31,0);
    tracep->declBus(c+8,"rf_rd0", false,-1, 31,0);
    tracep->declBus(c+9,"rf_rd1", false,-1, 31,0);
    tracep->declBus(c+80,"dbg_reg_rd", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+29+i*1,"reg_file", true,(i+0), 31,0);
    }
    tracep->declBus(c+1,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("data_mem ");
    tracep->declBus(c+93,"a", false,-1, 15,0);
    tracep->declBus(c+82,"d", false,-1, 31,0);
    tracep->declBit(c+62,"clk", false,-1);
    tracep->declBit(c+83,"we", false,-1);
    tracep->declBus(c+4,"spo", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("inst_mem ");
    tracep->declBus(c+61,"a", false,-1, 15,0);
    tracep->declBus(c+3,"spo", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VTop___024root__trace_init_top(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_init_top\n"); );
    // Body
    VTop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTop___024root__trace_register(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTop___024root__trace_full_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_top_0\n"); );
    // Init
    VTop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTop___024root__trace_full_sub_0(VTop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelf->Top__DOT__cpu__DOT__cur_pc),32);
    bufp->fullIData(oldp+3,(vlSelf->Top__DOT__inst),32);
    bufp->fullIData(oldp+4,(vlSelf->Top__DOT__data_mem__DOT__mem
                            [(0xffffU & (vlSelf->Top__DOT__cpu_dmem_addr 
                                         >> 2U))]),32);
    bufp->fullIData(oldp+5,(vlSelf->Top__DOT__cpu__DOT__commit_dmem_wa_reg),32);
    bufp->fullIData(oldp+6,(((IData)(4U) + vlSelf->Top__DOT__cpu__DOT__cur_pc)),32);
    bufp->fullIData(oldp+7,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__imm_t),32);
    bufp->fullIData(oldp+8,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
                            [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t]),32);
    bufp->fullIData(oldp+9,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file
                            [vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t]),32);
    bufp->fullIData(oldp+10,(vlSelf->Top__DOT__cpu__DOT__rf_wd),32);
    bufp->fullIData(oldp+11,(vlSelf->Top__DOT__cpu__DOT__alu_src0),32);
    bufp->fullIData(oldp+12,(vlSelf->Top__DOT__cpu__DOT__alu_src1),32);
    bufp->fullBit(oldp+13,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_we_t));
    bufp->fullBit(oldp+14,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src0_sel_t));
    bufp->fullBit(oldp+15,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_src1_sel_t));
    bufp->fullCData(oldp+16,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__alu_op_t),5);
    bufp->fullCData(oldp+17,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra0_t),5);
    bufp->fullCData(oldp+18,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_ra1_t),5);
    bufp->fullCData(oldp+19,(vlSelf->Top__DOT__cpu__DOT__my_decode__DOT__rf_wa_t),5);
    bufp->fullBit(oldp+20,(vlSelf->Top__DOT__cpu__DOT__commit_reg));
    bufp->fullIData(oldp+21,(vlSelf->Top__DOT__cpu__DOT__commit_pc_reg),32);
    bufp->fullIData(oldp+22,(vlSelf->Top__DOT__cpu__DOT__commit_inst_reg),32);
    bufp->fullBit(oldp+23,(vlSelf->Top__DOT__cpu__DOT__commit_halt_reg));
    bufp->fullBit(oldp+24,(vlSelf->Top__DOT__cpu__DOT__commit_reg_we_reg));
    bufp->fullCData(oldp+25,(vlSelf->Top__DOT__cpu__DOT__commit_reg_wa_reg),5);
    bufp->fullIData(oldp+26,(vlSelf->Top__DOT__cpu__DOT__commit_reg_wd_reg),32);
    bufp->fullBit(oldp+27,(vlSelf->Top__DOT__cpu__DOT__commit_dmem_we_reg));
    bufp->fullIData(oldp+28,(vlSelf->Top__DOT__cpu__DOT__commit_dmem_wd_reg),32);
    bufp->fullIData(oldp+29,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[0]),32);
    bufp->fullIData(oldp+30,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[1]),32);
    bufp->fullIData(oldp+31,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[2]),32);
    bufp->fullIData(oldp+32,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[3]),32);
    bufp->fullIData(oldp+33,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[4]),32);
    bufp->fullIData(oldp+34,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[5]),32);
    bufp->fullIData(oldp+35,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[6]),32);
    bufp->fullIData(oldp+36,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[7]),32);
    bufp->fullIData(oldp+37,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[8]),32);
    bufp->fullIData(oldp+38,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[9]),32);
    bufp->fullIData(oldp+39,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[10]),32);
    bufp->fullIData(oldp+40,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[11]),32);
    bufp->fullIData(oldp+41,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[12]),32);
    bufp->fullIData(oldp+42,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[13]),32);
    bufp->fullIData(oldp+43,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[14]),32);
    bufp->fullIData(oldp+44,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[15]),32);
    bufp->fullIData(oldp+45,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[16]),32);
    bufp->fullIData(oldp+46,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[17]),32);
    bufp->fullIData(oldp+47,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[18]),32);
    bufp->fullIData(oldp+48,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[19]),32);
    bufp->fullIData(oldp+49,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[20]),32);
    bufp->fullIData(oldp+50,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[21]),32);
    bufp->fullIData(oldp+51,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[22]),32);
    bufp->fullIData(oldp+52,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[23]),32);
    bufp->fullIData(oldp+53,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[24]),32);
    bufp->fullIData(oldp+54,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[25]),32);
    bufp->fullIData(oldp+55,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[26]),32);
    bufp->fullIData(oldp+56,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[27]),32);
    bufp->fullIData(oldp+57,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[28]),32);
    bufp->fullIData(oldp+58,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[29]),32);
    bufp->fullIData(oldp+59,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[30]),32);
    bufp->fullIData(oldp+60,(vlSelf->Top__DOT__cpu__DOT__my_regfile__DOT__reg_file[31]),32);
    bufp->fullSData(oldp+61,((0xffffU & (vlSelf->Top__DOT__cpu__DOT__cur_pc 
                                         >> 2U))),16);
    bufp->fullBit(oldp+62,(vlSelf->clk));
    bufp->fullBit(oldp+63,(vlSelf->rst));
    bufp->fullBit(oldp+64,(vlSelf->uart_we));
    bufp->fullCData(oldp+65,(vlSelf->uart_wdata),8);
    bufp->fullBit(oldp+66,(vlSelf->uart_ready));
    bufp->fullCData(oldp+67,(vlSelf->uart_rdata),8);
    bufp->fullBit(oldp+68,(vlSelf->uart_consumed));
    bufp->fullBit(oldp+69,(vlSelf->commit));
    bufp->fullBit(oldp+70,(vlSelf->commit_halt));
    bufp->fullIData(oldp+71,(vlSelf->commit_pc),32);
    bufp->fullIData(oldp+72,(vlSelf->commit_inst),32);
    bufp->fullBit(oldp+73,(vlSelf->commit_reg_we));
    bufp->fullCData(oldp+74,(vlSelf->commit_reg_wa),5);
    bufp->fullIData(oldp+75,(vlSelf->commit_reg_wd),32);
    bufp->fullBit(oldp+76,(vlSelf->commit_dmem_we));
    bufp->fullSData(oldp+77,(vlSelf->commit_dmem_wa),16);
    bufp->fullIData(oldp+78,(vlSelf->commit_dmem_wd),32);
    bufp->fullCData(oldp+79,(vlSelf->debug_reg_ra),5);
    bufp->fullIData(oldp+80,(vlSelf->debug_reg_rd),32);
    bufp->fullIData(oldp+81,(((0xa00003f4U == vlSelf->Top__DOT__cpu_dmem_addr)
                               ? (IData)(vlSelf->uart_rdata)
                               : ((0xa00003f8U == vlSelf->Top__DOT__cpu_dmem_addr)
                                   ? (IData)(vlSelf->uart_ready)
                                   : vlSelf->Top__DOT__data_mem__DOT__mem
                                  [(0xffffU & (vlSelf->Top__DOT__cpu_dmem_addr 
                                               >> 2U))]))),32);
    bufp->fullIData(oldp+82,(vlSelf->Top__DOT__cpu_dmem_wdata),32);
    bufp->fullBit(oldp+83,(((0xa00003f0U != (0xfffffff0U 
                                             & vlSelf->Top__DOT__cpu_dmem_addr)) 
                            & (IData)(vlSelf->Top__DOT__cpu_dmem_we))));
    bufp->fullIData(oldp+84,(vlSelf->Top__DOT__cpu_dmem_addr),32);
    bufp->fullBit(oldp+85,(vlSelf->Top__DOT__cpu_dmem_we));
    bufp->fullBit(oldp+86,(1U));
    bufp->fullIData(oldp+87,(vlSelf->Top__DOT__cpu__DOT__cur_npc_t),32);
    bufp->fullIData(oldp+88,(0x10000000U),32);
    bufp->fullIData(oldp+89,(0x2000000U),32);
    bufp->fullIData(oldp+90,(0x400000U),32);
    bufp->fullIData(oldp+91,(0x100000U),32);
    bufp->fullIData(oldp+92,(0x20U),32);
    bufp->fullSData(oldp+93,((0xffffU & (vlSelf->Top__DOT__cpu_dmem_addr 
                                         >> 2U))),16);
}
