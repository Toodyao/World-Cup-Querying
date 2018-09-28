cmake_minimum_required (VERSION 3.10)
project (World-Cup-Querying)

set (CMAKE_CXX_STANDARD 11)

# Add Google Test
set(google_test_dir third_party/googletest)
add_subdirectory(${google_test_dir})
include_directories(${google_test_dir}/googletest/include)
include_directories(${google_test_dir}/googlemock/include)

# Add RapidJSON
set(rapidjson_dir ./third_party/rapidjson)
include_directories(${rapidjson_dir}/include)

# Test files
add_subdirectory(test)

# Main files
add_subdirectory(src)