cmake_minimum_required(VERSION 3.5)

project(model_testing LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "--coverage")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(TEST_SOURCES
        test-model.cc
        basic_calc.cc
        basic_calc.h
        bank_calc.cc
        bank_calc.h
        model.h)

add_executable(model_testing ${TEST_SOURCES})

add_custom_target(gcov_report
        COMMAND ${CMAKE_MAKE_PROGRAM}
        COMMAND ./model_testing
        COMMAND lcov -c -d CMakeFiles/model_testing.dir -o coverage.info
        COMMAND lcov -r coverage.info '/usr*' -o coverage.info
        COMMAND genhtml coverage.info -o report
        COMMAND open report/index.html
        )
add_dependencies(gcov_report model_testing)

target_link_libraries(model_testing PRIVATE Qt${QT_VERSION_MAJOR}::Widgets GTest::GTest GTest::Main)
target_compile_options(model_testing PRIVATE -Wall -Werror -Wextra -O1)