#ifndef __SIM_IO_HPP__
#define __SIM_IO_HPP__

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <string>
#include <sys/termios.h>
#include <utility>
#include <vector>

// Handle I/O when from simulation begin to end
class SimIO {
private:
    inline static size_t __headlines = 0;
    inline static termios __originalTermios = {};
    inline static std::pair<size_t, size_t> __termSize = {0, 0}, __cursorPos = {0, 0}, __uartCursorPos = {0, 0};
    inline static std::vector<std::string> __buffer = {};

    inline static std::chrono::time_point<std::chrono::high_resolution_clock> __lastFlushTime;
    inline static uint32_t __time = 0, __instCount = 0;

private:
    static void start_uart_io();
    static void end_uart_io();

public:
    static void init(size_t _headlines);
    static void terminate();

    static bool char_waiting();
    static void putchar(char);
    static char getchar();

    // clocked flush
    static void flush(uint32_t _time, uint32_t _instCount);
    // forced flush
    static void flush();
};

#endif // __SIM_IO_HPP__