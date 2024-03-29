cmake_minimum_required(VERSION 3.27)
project(image_processor)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH exe)
set(MAIN_SOURCE
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/gui/login/LoginWindow.h ${CMAKE_SOURCE_DIR}/src/gui/login/LoginWindow.cpp ${CMAKE_SOURCE_DIR}/ui/loginwindow.ui
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
        ${CMAKE_SOURCE_DIR}/src/gui/list/ListWindow.h ${CMAKE_SOURCE_DIR}/src/gui/list/ListWindow.cpp ${CMAKE_SOURCE_DIR}/ui/listwindow.ui
        ${CMAKE_SOURCE_DIR}/src/gui/database/DatabaseWindow.h ${CMAKE_SOURCE_DIR}/src/gui/database/DatabaseWindow.cpp ${CMAKE_SOURCE_DIR}/ui/databasewindow.ui
        ${CMAKE_SOURCE_DIR}/src/gui/processing/ImageProcessingWindow.h ${CMAKE_SOURCE_DIR}/src/gui/processing/ImageProcessingWindow.cpp ${CMAKE_SOURCE_DIR}/ui/imageprocessingwindow.ui
)

target_link_libraries(image_processor PRIVATE Qt::Core Qt::Gui Qt::Widgets ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS image_processor
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(image_processor)
