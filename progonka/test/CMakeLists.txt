cmake_minimum_required(VERSION 3.0)
project(testfth)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(../ dim/)
target_link_libraries(${PROJECT_NAME} PRIVATE fuckthis GTest::gtest)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
   CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -pedantic -Wshadow -Wconversion -Wsign-conversion)
endif()

