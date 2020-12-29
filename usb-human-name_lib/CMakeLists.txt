cmake_minimum_required(VERSION 3.16)
project(usb_human_name CXX)

set(HEADER_FILES
        usb-human-name.h
        )

set(SOURCE_FILES
        usb-human-name.cpp
        )

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


add_library(usb_human_name SHARED STATIC ${SOURCE_FILES} ${HEADER_FILES})

install(TARGETS usb_human_name DESTINATION ${DIVISIBLE_INSTALL_LIB_DIR})
install(FILES usb-human-name.h DESTINATION ${DIVISIBLE_INSTALL_INCLUDE_DIR})
