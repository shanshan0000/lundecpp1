cmake_minimum_required(VERSION 3.16)
project(cpp)

set(CMAKE_CXX_STANDARD 14)
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

add_executable(cpp main.cpp evenement.h evenement.cpp timing.h timing.cpp log.h mylog.cpp mylog.h)