cmake_minimum_required(VERSION 3.8)
project(assembler LANGUAGES CXX)

add_executable(assembler main.cpp Assembler.h Assembler.cpp Parser.h Parser.cpp Encoder.h Encoder.cpp SymbolTable.h SymbolTable.cpp)

