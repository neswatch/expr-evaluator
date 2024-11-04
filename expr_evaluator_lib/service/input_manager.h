//
// Created by Julien  on 04/11/2024.
//

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "model/error/exception.h"

int is_exit_input(const char *input);

double evaluate_expression(const char *expression, Exception *exception_manager);

#endif //INPUT_MANAGER_H
