cmake_minimum_required(VERSION 3.16)

set(TESTAPP testapp)
set(COMMON_LIB common)
set(SIMULATOR_LIB simulator)

project(networking_projects VERSION 0.2.0 LANGUAGES C CXX)
set(CMAKE_C_STANDARD              17)
set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)

add_subdirectory(c)
