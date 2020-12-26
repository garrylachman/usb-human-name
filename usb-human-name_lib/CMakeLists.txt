project(usb_human_name)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)



set(HEADER_FILES
        library.h
        )

set(SOURCE_FILES
        library.cpp
        )

add_library(usb_human_name STATIC ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(usb_human_name
        PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION}
        )