include_directories("contrib")
add_executable(test_sum_lists test.cpp)
target_link_libraries(test_sum_lists Catch2::Catch2)
catch_discover_tests(test_sum_lists)