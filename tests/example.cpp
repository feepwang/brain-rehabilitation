#include "gtest/gtest.h"
#include "br/algorithm/fibonacci.h"

TEST(ExampleTest, Example) {
  ASSERT_EQ(br::al::Fibonacci<int>(3), 2);
}
