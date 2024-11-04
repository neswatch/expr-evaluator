project(expr-evaluator-lib C)


add_library(expr_evaluator_lib STATIC
        service/input_manager.c
        service/input_manager.h
        model/error/exception.h
        model/string_length.h)