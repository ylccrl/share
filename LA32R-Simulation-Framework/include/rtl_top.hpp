#ifndef __RTL_TOP_HPP__
#define __RTL_TOP_HPP__

#include <cstdint>

class VTop;
class VerilatedVcdC;

class RTLTop {
private:
    VTop * __vTop;
    VerilatedVcdC * __tfp;

    uint32_t __time;
    uint32_t __instCount;

    uint32_t * __dataMem;

private:
    void init();

    void clock_turnover();
    void step_cycle();

    void dump();

public:
    RTLTop();
    ~RTLTop();

    void step();

    bool uart_we() const;
    uint32_t uart_wdata() const;
    bool uart_consumed() const;

    bool commit() const;
    bool halt() const;

    // difftest
    uint32_t pc() const;
    uint32_t inst() const;

    // compare commission
    bool reg_we() const;
    uint32_t reg_wa() const;
    uint32_t reg_wd() const;
    bool dmem_we() const;
    uint32_t dmem_wa() const;
    uint32_t dmem_wd() const;

    // compare full status
    uint32_t reg(uint32_t _address) const;
    inline uint32_t dmem(uint32_t _address) const { return __dataMem[_address]; }

    // time & inst count
    inline uint32_t time() const { return __time; }
    inline uint32_t inst_count() const { return __instCount; }
};

#endif // __RTL_TOP_HPP__