#ifndef __DPI_C_HPP__
#define __DPI_C_HPP__

#include <svdpi.h>

extern "C" void expose_memory(int _dataMemDepth, const svLogicVecVal * _srcMem) ;
extern "C" void expose_configs(int _instMemStart, int _instMemDepth, const char * _instMemFile, int _dataMemStart, int _dataMemDepth, const char * _dataMemFile, char _coreType, unsigned char _io);

#endif // __DPI_C_HPP__