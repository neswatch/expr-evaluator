cmake_minimum_required(VERSION 3.22)
project(expr-evaluator)

set(CMAKE_C_STANDARD 23)

set(SOURCE_FILES main.c)
add_executable(expr_evaluator_run ${SOURCE_FILES})

include_directories(expr_evaluator_lib)
add_subdirectory(expr_evaluator_lib)

target_link_libraries(expr_evaluator_run expr_evaluator_lib)

add_subdirectory(Google_tests)

