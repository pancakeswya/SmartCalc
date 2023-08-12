cmake_minimum_required(VERSION 3.5)

project(SmartCalc_v2.0 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)

set (QRC_FILES Resources/resources.qrc)

set(PROJECT_SOURCES
        src/main.cc
        src/Controller/controller.h
        src/Controller/data_types.h
        src/ExtLibs/qcustomplot.cc
        src/ExtLibs/qcustomplot.h
        src/Model/model.h
        src/Model/basic_calc.cc
        src/Model/basic_calc.h
        src/Model/bank_calc.cc
        src/Model/bank_calc.h
        src/View/mainwindow.cc
        src/View/mainwindow.h
        src/View/mainwindow.ui
        src/View/secondwindow.cc
        src/View/secondwindow.h
        src/View/secondwindow.ui
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalc_v2.0
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES} ${QRC_FILES}
            )
else()
    add_executable(SmartCalc_v2.0
            ${PROJECT_SOURCES} ${QRC_FILES})
endif()

target_link_libraries(SmartCalc_v2.0 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

target_compile_options(SmartCalc_v2.0 PRIVATE -Wall -Werror -Wextra -O1)

set_target_properties(SmartCalc_v2.0 PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalc_v2.0)
endif()