#ifndef __CONFIGS_HPP__
#define __CONFIGS_HPP__

#include <cstdint>
#include <string>

// core type
enum class CoreType : unsigned char {
    SIMPLE_SINGLE_CYCLE,
    COMPLETE_SINGLE_CYCLE,
    PIPELINE
};

// difftest level
enum class Difftest : unsigned char {
    NO_DIFFTEST,
    COMPARE_COMMIT,
    COMPARE_FULL_STATUS
};

class Configs {
public:
    // rtl configs
    // corresponding to configs.vh
    inline static uint32_t instMemStart;
    inline static uint32_t instMemDepth;
    inline static std::string instMemFile;
    inline static uint32_t dataMemStart;
    inline static uint32_t dataMemDepth;
    inline static std::string dataMemFile;
    inline static CoreType coreType;
    inline static bool uartIO;

    // difftest configs
    // you can change the default values here
    inline static Difftest difftestLevel = Difftest::NO_DIFFTEST;
    inline static bool dumpWaveform = false;
    inline static std::string dumpPath = "waveform/waveform.vcd";
};

#endif // __CONFIGS_HPP__