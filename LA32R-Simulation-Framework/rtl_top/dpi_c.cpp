#include "dpi_c.hpp"
#include "configs.hpp"
#include <cstddef>
#include <cstdint>
#include <svdpi.h>

uint32_t * rtlDataMem;

extern "C" void expose_memory(int _dataMemDepth, const svLogicVecVal * _srcMem) {
    for(size_t i = 0; i < (1 << Configs::dataMemDepth); i++) {
        rtlDataMem[i] = _srcMem[i].aval;
    }
}

extern "C" void expose_configs(int _instMemStart, int _instMemDepth, const char * _instMemFile, int _dataMemStart, int _dataMemDepth, const char * _dataMemFile, char _coreType, unsigned char _uartIO) {
    Configs::instMemStart = _instMemStart;
    Configs::instMemDepth = _instMemDepth;
    Configs::instMemFile = _instMemFile;
    Configs::dataMemStart = _dataMemStart;
    Configs::dataMemDepth = _dataMemDepth;
    Configs::dataMemFile = _dataMemFile;
    Configs::coreType = static_cast<CoreType>(_coreType);
    Configs::uartIO = static_cast<bool>(_uartIO);
}