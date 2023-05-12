cmake_minimum_required(VERSION 3.25)
project(Project1)

FILE(GLOB SOURCE src/*.c)

set(CMAKE_C_STANDARD 90)

add_executable(Minesweeper Minesweeper.c
                            ${SOURCE}
                            )