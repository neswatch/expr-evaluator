project(expr-evaluator-lib C)

SET(HEADER_FILES
        hello.h

)

SET(SOURCE_FILES
        hello.c

)

add_library(expr_evaluator_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})