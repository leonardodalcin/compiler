cmake_minimum_required(VERSION 3.9)
project(Compiladores C)

set(CMAKE_C_STANDARD 99)

add_executable(Compiladores main.c tokens.h hash.c hash.h)