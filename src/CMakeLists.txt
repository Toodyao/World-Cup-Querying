cmake_minimum_required (VERSION 3.10)
project(Main)

add_library(src_files
        structures.h
        structures.cpp
        compare.hpp
        Heap.hpp
        my_time.h
        my_time.cpp
        )

add_executable(project_main
        main.cpp
        )

target_link_libraries(project_main src_files)