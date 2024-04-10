include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(RTL_TOP rtl_top.cpp dpi_c.cpp)

find_package(VERILATOR HINTS $ENV{VERILATOR_ROOT})
file(GLOB_RECURSE VSRCS ${CMAKE_SOURCE_DIR}/vsrc/your_vsrc/*.v)
verilate(   RTL_TOP
            SOURCES ${CMAKE_SOURCE_DIR}/vsrc/top.v ${VSRCS} ${CMAKE_SOURCE_DIR}/vsrc/mem_ip_sim/data_mem.v ${CMAKE_SOURCE_DIR}/vsrc/mem_ip_sim/inst_mem.v
            INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/vsrc/configs ${CMAKE_SOURCE_DIR}/vsrc/your_include
            TOP_MODULE Top
            PREFIX VTop
            DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/vtop
            TRACE
)

set(CMAKE_BUILD_TYPE Release)