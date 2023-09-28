cmake_minimum_required(VERSION 3.2)
project(run_unit_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-ggdb -fprofile-arcs -ftest-coverage")

SET(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")

find_package(GTest REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/../src/my_class/my_class.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/my_class/my_class_test.cmake)

file(GLOB MODEL_HEADERS "${CMAKE_CURRENT_LIST_DIR}/../src/model/*.hpp")
file(GLOB MODEL_SRC "${CMAKE_CURRENT_LIST_DIR}/../src/model/*.cpp")

file(GLOB ROOT_HEADERS  "${CMAKE_CURRENT_LIST_DIR}/../src/*.hpp")
file(GLOB ROOT_SRC "${CMAKE_CURRENT_LIST_DIR}/../src/*.cpp")

list(REMOVE_ITEM ROOT_SRC "${CMAKE_CURRENT_LIST_DIR}/../src/main.cpp")

add_executable(
        run_unit_tests
        ${MODEL_HEADERS}
        ${MODEL_SRC}
        ${ROOT_HEADERS}
        ${ROOT_SRC}
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
