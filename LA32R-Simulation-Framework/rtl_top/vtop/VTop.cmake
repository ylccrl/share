# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/opt/vlab/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(VTop_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(VTop_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(VTop_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(VTop_COVERAGE 0)
# Timing mode?  0/1
set(VTop_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(VTop_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(VTop_TRACE_VCD 1)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(VTop_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(VTop_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_dpi.cpp" "${VERILATOR_ROOT}/include/verilated_vcd_c.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(VTop_CLASSES_SLOW "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024root__Slow.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024root__DepSet_hc590b6dd__0__Slow.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024root__DepSet_h0d2e5939__0__Slow.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024unit__Slow.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024unit__DepSet_h1b4533a7__0__Slow.cpp")
# Generated module classes, fast-path, compile with highest optimization
set(VTop_CLASSES_FAST "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024root__DepSet_hc590b6dd__0.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024root__DepSet_h0d2e5939__0.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop___024unit__DepSet_hd7ebdb33__0.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(VTop_SUPPORT_SLOW "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop__Syms.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop__Trace__0__Slow.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(VTop_SUPPORT_FAST "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop__Dpi.cpp" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/rtl_top/vtop/VTop__Trace__0.cpp")
# All dependencies
set(VTop_DEPS "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/configs/configs.vh" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/mem_ip_sim/data_mem.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/mem_ip_sim/inst_mem.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/top.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/ADD4.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/ALU.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/CPU.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/DECODE.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/MUX1.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/PC.v" "/home/ubuntu/Desktop/LA32R-Simulation-Framework/vsrc/your_vsrc/REGFILE.v" "/opt/vlab/bin/verilator_bin" "/opt/vlab/share/verilator/include/verilated_std.sv")
# User .cpp files (from .cpp's on Verilator command line)
set(VTop_USER_CLASSES )
