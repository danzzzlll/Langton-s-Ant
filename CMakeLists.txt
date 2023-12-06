cmake_minimum_required(VERSION 3.5)

project(langtonAnt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        langtonant.h
        langtonant.cpp
        hexagon.h
        hexagon.cpp
        antitem.h
        antitem.cpp
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(langtonAnt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
        add_executable(langtonAnt
            ${PROJECT_SOURCES}
        )
endif()

target_link_libraries(langtonAnt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS langtonAnt DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(langtonAnt)
endif()
