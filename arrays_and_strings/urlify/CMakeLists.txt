include_directories("contrib")
add_executable(test_urlify test.cpp)
target_link_libraries(test_urlify Catch2::Catch2)
catch_discover_tests(test_urlify)