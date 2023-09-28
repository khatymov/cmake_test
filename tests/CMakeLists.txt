cmake_minimum_required(VERSION 3.2)
project(hodgepodge_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-ggdb -fprofile-arcs -ftest-coverage")

SET(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")

find_package(GTest REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/../src/my_class/my_class.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/my_class/my_class_test.cmake)

add_executable(
        run_unit_tests
        ${MY_CLASS}
        test.cpp
        ${MY_CLASS_TEST}
)
target_link_libraries(
        run_unit_tests
        gtest
        gtest_main
        pthread
)

enable_testing()

add_test(run_unit_tests run_unit_tests)