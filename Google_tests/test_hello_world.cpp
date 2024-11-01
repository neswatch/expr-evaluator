#include "gtest/gtest.h"

extern "C" {
#include "hello.h"
}

TEST(HelloSuite, HelloWorld) {
    EXPECT_EQ(hello(), 1);
}