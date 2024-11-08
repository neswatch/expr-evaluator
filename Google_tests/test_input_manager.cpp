#include <gtest/gtest.h>

extern "C" {
#include "service/input_manager.h"
}

TEST(IsExitInput, shouldWorkWithQuit) {
    const int result = is_exit_input("quit");
    ASSERT_EQ(1, result);
}

TEST(IsExitInput, shouldWorkWithExit) {
    const int result = is_exit_input("exit");
    ASSERT_EQ(1, result);
}

TEST(IsExitInput, shouldNotWorkWithQ) {
    const int result = is_exit_input("q");
    ASSERT_EQ(0, result);
}

TEST(IsExitInput, shouldNotWorkWithNumbers) {
    const int result = is_exit_input("2+2");
    ASSERT_EQ(0, result);
}

TEST(EvaluateExpression, shouldNotWorkWhenExpressionIsInvalid) {
    Exception exception_manager;
    exception_manager.code = 0;
    const double result = evaluate_expression("2+", &exception_manager);
    ASSERT_EQ(0, result);
    ASSERT_EQ(INVALID_EXPRESSION, exception_manager.code);
}
