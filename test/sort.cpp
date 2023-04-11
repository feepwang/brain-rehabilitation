#include "algorithms/algorithms.h"
#include "gtest/gtest.h"

using std::greater;

TEST(BubbleSort, LESS) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::BubbleSort(vec1);
  EXPECT_EQ(vec1, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::BubbleSort(vec2);
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(BubbleSort, GREATER) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::BubbleSort(vec1, greater<>());
  EXPECT_EQ(vec1, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::BubbleSort(vec2, greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(ExchangeSort, LESS) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::ExchangeSort(vec1);
  EXPECT_EQ(vec1, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::ExchangeSort(vec2);
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(ExchangeSort, GREATER) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::ExchangeSort(vec1, std::greater<>());
  EXPECT_EQ(vec1, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::ExchangeSort(vec2, std::greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(SelectionSort, LESS) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::SelectionSort(vec1);
  EXPECT_EQ(vec1, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::SelectionSort(vec2);
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(SelectionSort, GREATER) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::SelectionSort(vec1, std::greater<>());
  EXPECT_EQ(vec1, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::SelectionSort(vec2, std::greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(InsertionSort, LESS) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::InsertionSort(vec1);
  EXPECT_EQ(vec1, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::InsertionSort(vec2);
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(InsertionSort, GREATER) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::InsertionSort(vec1, std::greater<>());
  EXPECT_EQ(vec1, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::InsertionSort(vec2, std::greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}