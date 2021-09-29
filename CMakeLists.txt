project(switch_fp_comparison)
cmake_minimum_required(VERSION 3.21)

add_subdirectory(Catch2)

include(CTest)
include(Catch2/extras/Catch.cmake)
enable_testing()

add_executable(Sandbox main.cpp)
target_link_libraries(Sandbox Catch2WithMain)

catch_discover_tests(Sandbox)

# target_compile_options(Sandbox PUBLIC -g)
# target_link_options(Sandbox PUBLIC -g)
