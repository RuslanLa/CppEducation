include_directories("contrib")
add_executable(test_string_rotation test.cpp)
target_link_libraries(test_string_rotation Catch2::Catch2)
catch_discover_tests(test_string_rotation)