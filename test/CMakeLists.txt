cmake_minimum_required(VERSION 3.0)
project(testfth)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} test_fifth.cpp)

add_subdirectory(../ dim/)
target_link_directories(${PROJECT_NAME} PRIVATE ../build)
target_include_directories(${PROJECT_NAME} PRIVATE ../src)
target_link_libraries(${PROJECT_NAME} fuckthis GTest::gtest)
# target_link_libraries(${PROJECT_NAME} fuckthis GMock::gmock)
