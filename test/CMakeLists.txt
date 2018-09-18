cmake_minimum_required (VERSION 3.10)
project(Test)

enable_testing()

add_executable(project_test test.cpp)
target_link_libraries(project_test gtest gtest_main)