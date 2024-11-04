#include <stdio.h>
#include <string.h>
#include "model/string_length.h"
#include "model/error/exception.h"
#include "service/input_manager.h"


int main(void) {
    char str[MAX_STR_LEN];
    int exit_status = 0;
    Exception exception_manager;
    exception_manager.code = 0;

    do
    {
        printf("> ");
        fgets(str, MAX_STR_LEN, stdin);
        str[strlen(str) - 1] = '\0';
        exit_status = is_exit_input(str);
        if (!exit_status)
        {
            double result = evaluate_expression(str, &exception_manager);
            if (exception_manager.code == 0)
            {
                printf("%.3f", result);
            }
            else
            {
                printf("Error: %s", exception_manager.message);
            }

            printf("\n");
        }
    } while (!exit_status);

    return 0;
}
