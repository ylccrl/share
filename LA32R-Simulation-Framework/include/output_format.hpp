#ifndef __OUTPUT_FORMAT_HPP__
#define __OUTPUT_FORMAT_HPP__

#include <ostream>
#include <iomanip>

inline std::ostream & color_red(std::ostream & _ost) { return _ost << "\e[1;31m"; }
inline std::ostream & color_green(std::ostream & _ost) { return _ost << "\e[1;32m"; }
inline std::ostream & color_yellow(std::ostream & _ost) { return _ost << "\e[1;33m"; }
inline std::ostream & color_reset(std::ostream & _ost) { return _ost << "\e[0m"; }
inline std::ostream & hex_8(std::ostream & _ost) { return _ost << "0x" << std::hex << std::noshowbase << std::setw(8) << std::setfill('0') << std::right << std::uppercase; }
inline std::ostream & dec(std::ostream & _ost) { return _ost << std::dec << std::noshowbase << std::setw(0) << std::right; }
inline std::ostream & dec_l12(std::ostream & _ost) { return _ost << std::dec << std::noshowbase << std::setw(12) << std::setfill(' ') << std::left; }

inline std::ostream & hide_cursor(std::ostream & _ost) { return _ost << "\e[?25l"; }
inline std::ostream & show_cursor(std::ostream & _ost) { return _ost << "\e[?25h"; }
inline std::string set_cursor(size_t row, size_t col) { return "\e[" + std::to_string(row) + ";" + std::to_string(col) + "H"; }

#endif // __OUTPUT_FORMAT_HPP__