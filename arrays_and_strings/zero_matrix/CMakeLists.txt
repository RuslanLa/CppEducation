include_directories("contrib")
add_executable(test_zero_matrix test.cpp)
target_link_libraries(test_zero_matrix Catch2::Catch2)
catch_discover_tests(test_zero_matrix)