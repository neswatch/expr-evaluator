#include <gtest/gtest.h>

extern "C" {
#include "input_manager.h"
}

TEST(IsExitInput, shouldWorkWithQuit)
{
    const int result = is_exit_input("quit");
    ASSERT_EQ(1, result);
}

TEST(IsExitInput, shouldWorkWithExit)
{
    const int result = is_exit_input("exit");
    ASSERT_EQ(1, result);
}

TEST(IsExitInput, shouldNotWorkWithQ)
{
    const int result = is_exit_input("q");
    ASSERT_EQ(0, result);
}

TEST(IsExitInput, shouldNotWorkWithNumbers)
{
    const int result = is_exit_input("2+2");
    ASSERT_EQ(0, result);
}