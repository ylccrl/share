#include "rtl_top.hpp"
#include "VTop.h"
#include "configs.hpp"
#include "sim_io.hpp"
#include <cstdint>
#include <verilated_vcd_c.h>

extern uint32_t * rtlDataMem;

void RTLTop::init() {
    if(Configs::dumpWaveform) {
        __tfp = new VerilatedVcdC;
        __vTop->trace(__tfp, 0);
        Verilated::traceEverOn(true);
        __tfp->open(Configs::dumpPath.c_str());
    }

    // export configs
    __vTop->eval();
    rtlDataMem = new uint32_t[1 << Configs::dataMemDepth];
    __dataMem = rtlDataMem;

    // start status
    __vTop->clk = 0;
    __vTop->eval();
    dump();

    // reset
    __vTop->rst = 1;
    step_cycle();
    __vTop->rst = 0;
}

void RTLTop::clock_turnover() {
    __vTop->clk = !__vTop->clk;
    __vTop->eval();
    __time++;
    dump();
}

void RTLTop::step_cycle() {
    clock_turnover();
    clock_turnover();
}

void RTLTop::dump() {
    if(Configs::dumpWaveform) __tfp->dump(__time);
}

RTLTop::RTLTop() : __vTop(new VTop), __time(0), __instCount(0) {
    init();
}

RTLTop::~RTLTop() {
    if(Configs::dumpWaveform) {
        __tfp->close();
        delete __tfp;
    }
    delete __vTop;
}

void RTLTop::step() {
    do {
        step_cycle();
    } while(!commit());
    __instCount++;

    if(Configs::uartIO) {
        if(uart_consumed()) __vTop->uart_ready = 0;
        else if(!__vTop->uart_ready && SimIO::char_waiting()) {
            __vTop->uart_ready = 1;
            __vTop->uart_rdata = SimIO::getchar();
        }
        if(uart_we()) SimIO::putchar(uart_wdata());
    }
    SimIO::flush(time(), inst_count());
}

bool RTLTop::uart_we() const { return __vTop->uart_we; }
uint32_t RTLTop::uart_wdata() const { return __vTop->uart_wdata; }
bool RTLTop::uart_consumed() const { return __vTop->uart_consumed; }

bool RTLTop::commit() const { return __vTop->commit; }
bool RTLTop::halt() const { return __vTop->commit_halt; }

uint32_t RTLTop::pc() const { return __vTop->commit_pc; }
uint32_t RTLTop::inst() const { return __vTop->commit_inst; }

bool RTLTop::reg_we() const { return __vTop->commit_reg_we; }
uint32_t RTLTop::reg_wa() const { return __vTop->commit_reg_wa; }
uint32_t RTLTop::reg_wd() const { return __vTop->commit_reg_wd; }
bool RTLTop::dmem_we() const { return __vTop->commit_dmem_we; }
uint32_t RTLTop::dmem_wa() const { return __vTop->commit_dmem_wa; }
uint32_t RTLTop::dmem_wd() const { return __vTop->commit_dmem_wd; }

uint32_t RTLTop::reg(uint32_t _address) const {
    __vTop->debug_reg_ra = _address;
    __vTop->eval();
    return __vTop->debug_reg_rd;
}