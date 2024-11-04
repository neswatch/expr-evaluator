//
// Created by Julien  on 04/11/2024.
//

#include "input_manager.h"

#include <string.h>
#include <stdlib.h>

#define MAX_TMP_ARRAY_SIZE 1024

int is_exit_input(const char* input)
{
    if (strcmp(input , "exit") == 0) return 1;
    if (strcmp(input, "quit") == 0) return 1;
    return 0;
}

int is_a_number(const char c)
{
    return c >= '0' && c <= '9';
}

int is_operator(const char c)
{
    return c == '+';
}

double sum(const int* elts, const int elts_size)
{
    double result = 0;
    for (int i = 0; i < elts_size; i++)
    {
        result += elts[i];
    }
    return result;
}

double evaluate_expression(const char *expression, Exception *exception_manager) {
    int elts[MAX_TMP_ARRAY_SIZE];
    int elts_size = 0;
    int has_operator = 0;

    char tmp[MAX_STR_LEN];
    int i = 0;

    while (expression[i] != '\0') {
        if (is_a_number(expression[i])) {
            int j = 0;
            while (is_a_number(expression[i])) {
                tmp[j] = expression[i];
                i++;
                j++;
            }
            tmp[j] = '\0';
            elts[elts_size] = (int) strtol(tmp, NULL, 10);
            elts_size++;
        } else if (is_operator(expression[i]) || expression[i] == ' ') {
            has_operator = 1;
            i++;
        } else {
            exception_manager->code = INVALID_EXPRESSION;
            strcpy(exception_manager->message, "Invalid expression");
            return 0;
        }
    }

    if (has_operator && (elts_size < 2)) {
        exception_manager->code = INVALID_EXPRESSION;
        strcpy(exception_manager->message, "Invalid expression");
        return 0;
    }

    return sum(elts, elts_size);
}
