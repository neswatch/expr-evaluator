//
// Created by Julien  on 04/11/2024.
//

#include "input_manager.h"

#include <string.h>

int is_exit_input(const char* input)
{
    if (strcmp(input , "exit") == 0) return 1;
    if (strcmp(input, "quit") == 0) return 1;
    return 0;
}
