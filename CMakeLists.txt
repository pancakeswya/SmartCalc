cmake_minimum_required(VERSION 3.5)

project(SmartCalc_v2.0 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -O3 -Wno-deprecated-declarations")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)

add_library(QCustomPlot STATIC
                external/qcustomplot.cc
                external/qcustomplot.h)

target_link_libraries(QCustomPlot PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)

set(QRC_FILES resources/resources.qrc)

set(PROJECT_SOURCES
        smartcalc/main.cc
        smartcalc/controller/controller.h
        smartcalc/types/data_types.h
        smartcalc/model/model.h
        smartcalc/model/basic_calc.cc
        smartcalc/model/basic_calc.h
        smartcalc/model/bank_calc.cc
        smartcalc/model/bank_calc.h
        smartcalc/view/mainwindow.cc
        smartcalc/view/mainwindow.h
        smartcalc/view/mainwindow.ui
        smartcalc/view/secondwindow.cc
        smartcalc/view/secondwindow.h
        smartcalc/view/secondwindow.ui
        )

        
include_directories("smartcalc/")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES} ${QRC_FILES}
            )
else()
    add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES} ${QRC_FILES})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets QCustomPlot)

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
