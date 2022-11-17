cmake_minimum_required(VERSION 3.21)
project(AsincronicaPMD2 C)

set(CMAKE_C_STANDARD 99)

add_executable(AsincronicaPMD2 main.c merch.c merch.h orderElements.h orderElements.c CircleDList.c CircleDList.h CircleList.c CircleList.h)

