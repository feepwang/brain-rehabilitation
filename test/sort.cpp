#include "algorithms/bubble_sort.h"
#include "algorithms/exchange_sort.h"
#include "gtest/gtest.h"

TEST(BubbleSort, LESS) {
  std::vector<int> vec{3, 2, 1, 5, 4};
  br::BubbleSort(vec);
  EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(BubbleSort, GREATER) {
  std::vector<int> vec{3, 2, 1, 5, 4};
  br::BubbleSort(vec, std::greater<int>());
  EXPECT_EQ(vec, std::vector<int>({5, 4, 3, 2, 1}));
}

TEST(ExchangeSort, LESS) {
  std::vector<int> vec{3, 2, 1, 5, 4};
  br::ExchangeSort(vec);
  EXPECT_EQ(vec, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(ExchangeSort, GREATER) {
  std::vector<int> vec{3, 2, 1, 5, 4};
  br::ExchangeSort(vec, std::greater<int>());
  EXPECT_EQ(vec, std::vector<int>({5, 4, 3, 2, 1}));
}