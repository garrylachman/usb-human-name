project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/data)
file(COPY data/usb.ids DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)

# adding the Google_Tests_run target
add_executable(Google_Tests_run DBFileLoadTest.cpp)

# linking Google_Tests_run with lib which will be tested
target_link_libraries(Google_Tests_run usb_human_name)

target_link_libraries(Google_Tests_run gtest gtest_main)
