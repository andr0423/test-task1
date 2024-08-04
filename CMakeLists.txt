cmake_minimum_required(VERSION 3.0)

project( "converter" )

enable_testing()
add_subdirectory( gtest )
add_executable( main.exe main.cpp conv.cpp)
target_link_libraries( main.exe gtest_main gmock_main )
