cmake_minimum_required(VERSION 3.27)
project(EfreiDataMaster C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(EfreiDataMaster
        cdataframe.c
        cdataframe.h
        column.c
        column.h
        interface.c
        interface.h
        main.c
        advanced_column.c
        advanced_column.h
        advanced_cdataframe.c
        advanced_cdataframe.h)