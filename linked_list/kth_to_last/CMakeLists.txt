include_directories("contrib")
add_executable(test_kth_to_last test.cpp)
target_link_libraries(test_kth_to_last Catch2::Catch2)
catch_discover_tests(test_kth_to_last)