cmake_minimum_required (VERSION 3.10)
project(Main)

add_executable(project_main main.cpp)
target_link_libraries(project_main rapidjson)