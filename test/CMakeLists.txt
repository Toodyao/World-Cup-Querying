cmake_minimum_required (VERSION 3.10)
project(Test)

enable_testing()

set(src_root ../src)
include_directories(${src_root}/)

add_executable(project_test
        test.cpp
        time_test.cpp
        structure_test.cpp
        algorithm_test.cpp
        json_test.cpp
        demo_test.cpp)

target_link_libraries(project_test gtest gtest_main)
target_link_libraries(project_test src_files)
