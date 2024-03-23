#include "br/al/fibonacci.h"

#include "gtest/gtest.h"

TEST(FIBONACCI, INTEGER) {
  //
  EXPECT_EQ(br::al::Fibonacci(3), 2);
}
