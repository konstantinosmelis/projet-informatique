cmake_minimum_required(VERSION 3.27)
project(image_processor)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH exe)
set(MAIN_SOURCE
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/gui/mainwindow.h
        ${CMAKE_SOURCE_DIR}/src/gui/mainwindow.cpp
        ${CMAKE_SOURCE_DIR}/src/gui/mainwindow.ui
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

qt_standard_project_setup()

add_executable(image_processor
        ${MAIN_SOURCE}
        ${CMAKE_SOURCE_DIR}/src/descriptor/ImageDescriptor.h ${CMAKE_SOURCE_DIR}/src/descriptor/ImageDescriptor.cpp
        ${CMAKE_SOURCE_DIR}/src/image/Image.h ${CMAKE_SOURCE_DIR}/src/image/Image.cpp
        ${CMAKE_SOURCE_DIR}/src/database/Database.h ${CMAKE_SOURCE_DIR}/src/database/Database.cpp
        ${CMAKE_SOURCE_DIR}/src/user/User.h ${CMAKE_SOURCE_DIR}/src/user/User.cpp
        ${CMAKE_SOURCE_DIR}/src/gui/secondwindow.h ${CMAKE_SOURCE_DIR}/src/gui/secondwindow.cpp ${CMAKE_SOURCE_DIR}/src/gui/secondwindow.ui
        ${CMAKE_SOURCE_DIR}/src/gui/databasewindow.h ${CMAKE_SOURCE_DIR}/src/gui/databasewindow.cpp ${CMAKE_SOURCE_DIR}/src/gui/databasewindow.ui
        ${CMAKE_SOURCE_DIR}/src/gui/traitementimagewindow.h ${CMAKE_SOURCE_DIR}/src/gui/traitementimagewindow.cpp ${CMAKE_SOURCE_DIR}/src/gui/traitementimagewindow.ui
)

target_link_libraries(image_processor Qt::Core Qt::Gui Qt::Widgets ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS image_processor
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(image_processor)
