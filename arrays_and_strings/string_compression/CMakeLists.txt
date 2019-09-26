include_directories("contrib")
add_executable(test_compress_string test.cpp)
target_link_libraries(test_compress_string Catch2::Catch2)
catch_discover_tests(test_compress_string)