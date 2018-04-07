cmake_minimum_required(VERSION 3.9)
project(Compiladores C)

set(CMAKE_C_STANDARD 99)

add_executable(Compiladores etapa1/main.c etapa1/tokens.h etapa1/hash.c etapa1/hash.h etapa1/main.c)