#ifndef __SIMULATOR_HPP__
#define __SIMULATOR_HPP__

#include "rtl_top.hpp"
#include "sim_top.hpp"
#include <string>

class Simulator {
private:
    RTLTop __rtlTop;
    SimTop __simTop;

public:
    inline Simulator() : __rtlTop(), __simTop() {}

    void simulate();

private:
    class Diff {
    public:
        bool haltDiff : 1;
        bool pcDiff : 1;
        bool instDiff : 1;
        bool regWEDiff : 1;
        bool regWADiff : 1;
        bool regWDDiff : 1;
        bool dmemWEDiff : 1;
        bool dmemWADiff : 1;
        bool dmemWDDiff : 1;
        bool regDiff : 1;
        bool dmemDiff : 1;

    public:
        inline Diff() : haltDiff(false), pcDiff(false), instDiff(false), regWEDiff(false), regWADiff(false), regWDDiff(false), dmemWEDiff(false), dmemWADiff(false), dmemWDDiff(false), regDiff(false), dmemDiff(false) {}

        inline operator bool() { return haltDiff || pcDiff || instDiff || regWEDiff || regWADiff || regWDDiff || regDiff || dmemWEDiff || dmemWADiff || dmemWDDiff || dmemDiff; }
    };

    Diff difftest();
    template<class __TYPE>
    void print_difference(int, int, int, const std::string &, __TYPE, __TYPE);
    template<class __TYPE>
    void print_difference_mute(int, int, int, const std::string &, __TYPE, __TYPE);
    void print_difference(const Diff &);

    void abort();
    void hit_good_trap();
    void end();
};

#endif // __SIMULATOR_HPP__