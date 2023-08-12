cmake_minimum_required(VERSION 3.5)

project(model_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_program(GCOV gcov)
find_program(LCOV lcov)

set(TEST_SOURCES
        test-model.cc
        basic_calc.cc
        basic_calc.h
        bank_calc.cc
        bank_calc.h
        model.h)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

add_custom_target(test
        COMMAND ${CMAKE_MAKE_PROGRAM}
        COMMAND ./${PROJECT_NAME}
        )
add_custom_target(check-valgrind
        COMMAND ${CMAKE_MAKE_PROGRAM}
        COMMAND valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full ./${PROJECT_NAME}
        )

if (GCOV AND LCOV)
    set(CMAKE_CXX_FLAGS "--coverage")
    add_custom_target(gcov_report
            COMMAND ${CMAKE_MAKE_PROGRAM}
            COMMAND ./${PROJECT_NAME}
            COMMAND lcov -c -d CMakeFiles/${PROJECT_NAME}.dir -o coverage.info
            COMMAND lcov -r coverage.info '/usr*' -o coverage.info
            COMMAND genhtml coverage.info -o report
            COMMAND open report/index.html
            )
    add_dependencies(gcov_report ${PROJECT_NAME})
else()
    message(WARNING "Cannot find utils for coverage(lcov|gcov)")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets GTest::GTest GTest::Main)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -O1)