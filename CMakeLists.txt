cmake_minimum_required(VERSION 3.16)
project(usb_human_name)

set(CMAKE_CXX_STANDARD 17)

include_directories(usb-human-name_lib)
add_subdirectory(usb-human-name_lib)

add_subdirectory(Google_tests)