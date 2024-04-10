#ifndef __SIM_TOP_HPP__
#define __SIM_TOP_HPP__

#include <cstdint>

class SimTop {
private:
    bool __halt;
    uint32_t __pc, __pcNext;
    uint32_t __inst;
    bool __regWE;
    uint32_t __regWA;
    uint32_t __regWD;
    bool __memWE;
    uint32_t __memWA;
    uint32_t __memWD;

    uint32_t * __reg;
    uint32_t * __instMem;
    uint32_t * __dataMem;

public:
    // initialize inst memory & data memory
    SimTop();

    void step();

    inline bool halt() const { return __halt; }

    // difftest
    inline uint32_t pc() const { return __pc; }
    inline uint32_t inst() const { return __inst; }

    // compare commission
    inline bool reg_we() const { return __regWE; }
    inline uint32_t reg_wa() const { return __regWA; }
    inline uint32_t reg_wd() const { return __regWD; }
    inline bool dmem_we() const { return __memWE; }
    inline uint32_t dmem_wa() const { return __memWA; }
    inline uint32_t dmem_wd() const { return __memWD; }

    // compare full status
    inline uint32_t reg(uint32_t _address) const { return __reg[_address]; }
    inline uint32_t dmem(uint32_t _address) const { return __dataMem[_address]; }

private:
    inline static bool check(uint32_t _inst, uint32_t _mask, uint32_t _value) { return (_inst & _mask) == _value; }
    inline static uint32_t extract(uint32_t _inst, uint32_t _mask, uint32_t _offset) { return (_inst & (_mask << _offset)) >> _offset; }

    inline void fetch();
    inline void decode_execute();
    inline void write();
};

#endif