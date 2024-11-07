#include <gtest/gtest.h>

extern "C" {
#include "service/input_manager.h"
}

TEST(EvaluationAddition, shouldWorkWithTwoNumbers) {
Exception exception_manager;
exception_manager.code = 0;
const double result = evaluate_expression("2+2", &exception_manager);
ASSERT_EQ(4.0, result);
ASSERT_EQ(0, exception_manager.code);
}

TEST(EvaluationAddition, shouldWorkWithTwoNumbersAndSpaces) {
Exception exception_manager;
exception_manager.code = 0;
const double result = evaluate_expression("2+ 2", &exception_manager);
ASSERT_EQ(4, result);
ASSERT_EQ(0, exception_manager.code);
}

TEST(EvaluationAddition, shouldWorkWithThreeNumbers) {
Exception exception_manager;
exception_manager.code = 0;
const double result = evaluate_expression("2+2+3", &exception_manager);
ASSERT_EQ(7.0, result);
ASSERT_EQ(0, exception_manager.code);
}