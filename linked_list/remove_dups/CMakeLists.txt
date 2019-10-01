include_directories("contrib")
add_executable(test_remove_dups test.cpp)
target_link_libraries(test_remove_dups Catch2::Catch2)
catch_discover_tests(test_remove_dups)