cmake_minimum_required(VERSION 3.0)
project(fuckthis)

set(HEADERS
    src/progonka.h
    src/chebyshev.h
    src/CSR_matrix.h
    src/dense_matrix.h
    src/gaussSeidel.h
    src/jacobi.h
    src/linspace.h
    src/three_diag_matrix.h
    src/vec_operations.h
)

add_library(${PROJECT_NAME} INTERFACE ..)
target_include_directories(${PROJECT_NAME} INTERFACE .)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

