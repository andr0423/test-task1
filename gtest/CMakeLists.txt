cmake_minimum_required(VERSION 3.0)

project("converter")

# Add test cpp file
add_executable( test.exe test.cpp )

# Link test executable against gtest & gtest_main
target_link_libraries( test.exe gtest gtest_main gmock gmock_main )

add_test(NAME test.exe COMMAND test.exe)
