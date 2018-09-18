cmake_minimum_required (VERSION 3.10)
project(Main)

# Add RapidJSON (need to refine with CMakeLists.txt in root dirctory)
set(rapidjson_dir ./third_party/rapidjson)
include_directories(${rapidjson_dir}/include)

add_executable(project_main main.cpp structures.h reader.h reader.cpp)
target_link_libraries(project_main rapidjson)