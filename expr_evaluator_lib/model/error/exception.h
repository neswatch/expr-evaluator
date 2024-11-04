//
// Created by julie on 04/11/2024.
//

#ifndef EXPR_EVALUATOR_EXCEPTION_H
#define EXPR_EVALUATOR_EXCEPTION_H

#include "model/string_length.h"

#define INVALID_EXPRESSION 1

typedef struct {
    int code;
    char message[MAX_STR_LEN];
} Exception;

#endif //EXPR_EVALUATOR_EXCEPTION_H
