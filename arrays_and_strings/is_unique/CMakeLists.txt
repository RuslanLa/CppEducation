include_directories("contrib")
add_executable(test_is_unique test.cpp)
target_link_libraries(test_is_unique Catch2::Catch2)
catch_discover_tests(test_is_unique)