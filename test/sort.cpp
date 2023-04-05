#include "algorithms/bubble_sort.h"
#include "gtest/gtest.h"

TEST(BubbleSort, BubbleSort) {
  std::vector<int> vec{3, 2, 1, 5, 4};
  br::BubbleSort(vec);
  EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}