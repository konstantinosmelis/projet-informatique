cmake_minimum_required(VERSION 3.27)
project(image_processor)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH exe)
set(MAIN_SOURCE
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/descriptor/ImageDescriptor.h ${CMAKE_SOURCE_DIR}/src/descriptor/ImageDescriptor.cpp
        ${CMAKE_SOURCE_DIR}/src/image/Image.h ${CMAKE_SOURCE_DIR}/src/image/Image.cpp
        ${CMAKE_SOURCE_DIR}/src/database/Database.h ${CMAKE_SOURCE_DIR}/src/database/Database.cpp
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(image_processor ${MAIN_SOURCE})

target_link_libraries(image_processor Qt::Core Qt::Gui Qt::Widgets ${OpenCV_LIBS})
