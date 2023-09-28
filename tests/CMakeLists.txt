cmake_minimum_required(VERSION 3.2)
project(run_unit_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -ggdb -fprofile-arcs -ftest-coverage")

find_package(GTest REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/my_class/my_class_test.cmake)

file(GLOB HEADERS "${CMAKE_CURRENT_LIST_DIR}/../src/*.hpp" "${CMAKE_CURRENT_LIST_DIR}/../src/model/*.hpp")
file(GLOB SRC "${CMAKE_CURRENT_LIST_DIR}/../src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/../src/model/*.cpp")

list(REMOVE_ITEM SRC "${CMAKE_CURRENT_LIST_DIR}/../src/main.cpp")

add_executable(
        ${PROJECT_NAME}
        ${HEADERS}
        ${SRC}
        test.cpp
        ${MY_CLASS_TEST}
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../src")

target_link_libraries(
        ${PROJECT_NAME}
        gtest
        gtest_main
        pthread
)

enable_testing()

add_test(run_unit_tests ${PROJECT_NAME})
