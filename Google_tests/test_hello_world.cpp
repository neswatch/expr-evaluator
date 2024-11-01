#include "gtest/gtest.h"

extern "C" {
#include "hello.h"
}

TEST(HelloSuite, HelloWorldTest) {
    EXPECT_EQ(hello(), 0);
}