cmake_minimum_required (VERSION 3.10)
project (World-Cup-Querying)

# Add Google Test
set(google_test_dir ./googletest-master)
add_subdirectory(${google_test_dir})
include_directories(${google_test_dir}/googletest/include)
include_directories(${google_test_dir}/googlemock/include)

# Add RapidJSON
set(rapidjson_dir ./rapidjson)
include_directories(${rapidjson_dir})

# Main files
add_executable(main main.cpp)
target_link_libraries(main gtest gtest_main)