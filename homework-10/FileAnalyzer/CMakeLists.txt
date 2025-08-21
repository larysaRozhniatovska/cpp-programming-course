cmake_minimum_required(VERSION 3.5)

project(FileAnalyzer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)



add_executable(FileAnalyzer
    scr/main.cpp
    scr/mainwindow.cpp
    scr/mainwindow.h
    scr/mainwindow.ui
    scr/file_item.h scr/file_item.cpp
    scr/file_scanner.h scr/file_scanner.cpp
)

qt_add_resources(RSS_SOURCES resources/resources.qrc)

target_sources(FileAnalyzer PRIVATE ${RSS_SOURCES} )

target_link_libraries(FileAnalyzer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${RESOURCES})
