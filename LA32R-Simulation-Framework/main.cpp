#include "configs.hpp"
#include "simulator.hpp"
#include <exception>
#include <iostream>
#include <string>

int main(int argc, char ** argv) {
    // parse arguments
    try {
        for(int i = 1; i < argc; i++) {
            auto arg = std::string(argv[i]);
            if(arg == "-ln") {
                Configs::difftestLevel = Difftest::NO_DIFFTEST;
            }
            else if(arg == "-lc") {
                Configs::difftestLevel = Difftest::COMPARE_COMMIT;
            }
            else if(arg == "-lf") {
                Configs::difftestLevel = Difftest::COMPARE_FULL_STATUS;
            }
            else if(arg == "--dump-waveform" || arg == "-d") {
                Configs::dumpWaveform = true;
            }
            else if(i + 1 == argc) {
                throw std::invalid_argument("Missing argument for '" + arg + "'");
            }
            else if(arg == "--difftest-level" || arg == "-l") {
                i++;
                arg = std::string(argv[i]);
                if(arg == "no-difftest") {
                    Configs::difftestLevel = Difftest::NO_DIFFTEST;
                }
                else if(arg == "compare-commit") {
                    Configs::difftestLevel = Difftest::COMPARE_COMMIT;
                }
                else if(arg == "compare-full-status") {
                    Configs::difftestLevel = Difftest::COMPARE_FULL_STATUS;
                }
                else {
                    throw std::invalid_argument("Invalid argument '" + arg + "' for --difftest-level");
                }
            }
            else if(arg == "--dump-path" || arg == "-p") {
                i++;
                Configs::dumpPath = std::string(argv[i]);
            }
            else {
                throw std::invalid_argument("Invalid argument '" + arg + "'");
            }
        }
    }
    catch(const std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "    --difftest-level <level>, -l <level>            Set difftest level" << std::endl;
        std::cout << "        -ln                                         -   no-difftest" << std::endl;
        std::cout << "        -lc                                         -   compare-commit" << std::endl;
        std::cout << "        -lf                                         -   compare-full-status" << std::endl;
        std::cout << "    --dump-waveform, -d                             Dump waveform" << std::endl;
        std::cout << "    --dump-path <path>, -p <path>                   Set dump path" << std::endl;
        return -1;
    }

    // difftest
    auto simulator = Simulator();
    simulator.simulate();

    return 0;
}