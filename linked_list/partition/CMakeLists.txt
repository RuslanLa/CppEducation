include_directories("contrib")
add_executable(test_partition test.cpp)
target_link_libraries(test_partition Catch2::Catch2)
catch_discover_tests(test_partition)