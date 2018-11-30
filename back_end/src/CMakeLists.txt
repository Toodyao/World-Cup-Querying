cmake_minimum_required (VERSION 3.10)
project(Main)

add_library(src_files
        structures.h
        compare.hpp
        heap.hpp
        my_time.h
        my_time.cpp
        timeline.h
        timeline.cpp
        backend.cpp
        backend.h
        rank.hpp
        demo.cpp
        demo.h
        hash.hpp
        my_vector.hpp
        player.cpp
        team.cpp
        team_event.cpp
        match.cpp
        matches.cpp knockout.cpp knockout.h comments.cpp comments.h)

add_executable(project_main
        main.cpp
        )

target_link_libraries(project_main src_files)