#include <gtest/gtest.h>

extern "C" {
#include "service/input_manager.h"
}

TEST(EvaluateSubstraction, shouldWorkWithTwoNumbers) {
    Exception exception_manager;
    exception_manager.code = 0;
    const double result = evaluate_expression("2-2", &exception_manager);
    ASSERT_EQ(0.0, result);
    ASSERT_EQ(0, exception_manager.code);
}

TEST(EvaluateSubstraction, shouldWorkWithTwoNumbersAndSpaces) {
    Exception exception_manager;
    exception_manager.code = 0;
    const double result = evaluate_expression("2- 2", &exception_manager);
    ASSERT_EQ(0, result);
    ASSERT_EQ(0, exception_manager.code);
}

TEST(EvaluateSubstraction, shouldWorkWithFirstNegativeNumber) {
    Exception exception_manager;
    exception_manager.code = 0;
    const double result = evaluate_expression("-2-3", &exception_manager);
    ASSERT_EQ(-5.0, result);
    ASSERT_EQ(0, exception_manager.code);
}

TEST(EvaluateSubstraction, shouldWorkWIthThreeNumbers) {
    Exception exception_manager;
    exception_manager.code = 0;
    const double result = evaluate_expression("2-5+10", &exception_manager);
    ASSERT_EQ(7.0, result);
    ASSERT_EQ(0, exception_manager.code);
}