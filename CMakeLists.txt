cmake_minimum_required(VERSION 3.0)
project(fuckthis)

set(HEADERS
    src/progonka.h
)

add_library(${PROJECT_NAME} INTERFACE src/three_diag_matrix.h src/vec_operations.h  src/mpi.h)
target_include_directories(${PROJECT_NAME} INTERFACE .)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

