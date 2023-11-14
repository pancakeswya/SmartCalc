cmake_minimum_required(VERSION 3.5)

project(SmartCalc VERSION 2.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Charts REQUIRED)

include_directories("smartcalc/")
include_directories("external/DateTime/src")

add_library(DateTime STATIC
                external/DateTime/src/timespan.cpp
                external/DateTime/src/timespan.h
                external/DateTime/src/datetime.cpp
                external/DateTime/src/datetime.h)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(QRC_FILES resources/resources.qrc)

set(PROJECT_SOURCES
        smartcalc/main.cc
        smartcalc/types/data_types.h
        smartcalc/util/date_conv_util.h
        smartcalc/util/calc_util.h
        smartcalc/model/basic_calc.cc
        smartcalc/model/basic_calc.h
        smartcalc/model/credit_calc.cc
        smartcalc/model/credit_calc.h
        smartcalc/model/deposit_calc.cc
        smartcalc/model/deposit_calc.h
        smartcalc/model/graph_calc.cc
        smartcalc/model/graph_calc.h
        smartcalc/model/model.cc
        smartcalc/model/model.h
        smartcalc/controller/input_handler.cc
        smartcalc/controller/input_handler.h
        smartcalc/controller/controller.cc
        smartcalc/controller/controller.h
        smartcalc/view/mainwindow.cc
        smartcalc/view/mainwindow.h
        smartcalc/view/mainwindow.ui
        smartcalc/view/secondwindow.cc
        smartcalc/view/secondwindow.h
        smartcalc/view/secondwindow.ui
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES} ${QRC_FILES}
            )
else()
    add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES} ${QRC_FILES})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts DateTime)

set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
