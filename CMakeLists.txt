cmake_minimum_required(VERSION 3.17)
project(compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(compiler main.cpp scanner/TypeWord.cpp scanner/Scanner.cpp scanner/Word.cpp scanner/GScanner.cpp)