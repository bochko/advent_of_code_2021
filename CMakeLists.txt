cmake_minimum_required(VERSION 3.0.0)
project(advent_of_code_2021 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(gtest_force_shared_crt on CACHE BOOL "" FORCE)
add_subdirectory(lib/googletest)
include(GoogleTest)
enable_testing()

add_library(1_sonar_sweep)
target_sources(1_sonar_sweep PRIVATE src/1_sonar_sweep.cpp)
target_include_directories(1_sonar_sweep PUBLIC src)

add_library(2_dive)
target_sources(2_dive PRIVATE src/2_dive.cpp)
target_include_directories(2_dive PUBLIC src)

add_executable(advent_of_code_2021 test/advent_of_code_2021.cpp)
target_link_libraries(advent_of_code_2021 
    gtest_main
    1_sonar_sweep
    2_dive
)
gtest_discover_tests(advent_of_code_2021)