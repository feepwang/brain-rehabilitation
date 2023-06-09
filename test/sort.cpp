#include <functional>

#include "algorithms/algorithms.h"
#include "algorithms/merge_sort.h"
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

TEST(ShellSort, LESS) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::ShellSort(vec1);
  EXPECT_EQ(vec1, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::ShellSort(vec2);
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(ShellSort, GREATER) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::ShellSort(vec1, std::greater<>());
  EXPECT_EQ(vec1, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::ShellSort(vec2, std::greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(MergeSort, LESS) {
  std::vector<int> result(5);
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::MergeSort(vec1, 0, vec1.size(), result);
  EXPECT_EQ(result, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::MergeSort(vec2, 0, 0, result);
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(MergeSort, GREATER) {
  std::vector<int> result(5);
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::MergeSort(vec1, 0, vec1.size(), result, std::greater<>());
  EXPECT_EQ(result, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::MergeSort(vec2, 0, 0, result, std::greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(QuickSort, LESS) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::QuickSort(vec1, 0, vec1.size());
  EXPECT_EQ(vec1, std::vector<int>({1, 2, 3, 4, 5}));

  std::vector<int> vec2{};
  br::QuickSort(vec2, 0, vec2.size());
  EXPECT_EQ(vec2, std::vector<int>());
}

TEST(QuickSort, GREATER) {
  std::vector<int> vec1{3, 2, 1, 5, 4};
  br::QuickSort(vec1, 0, vec1.size(), std::greater<>());
  EXPECT_EQ(vec1, std::vector<int>({5, 4, 3, 2, 1}));

  std::vector<int> vec2{};
  br::QuickSort(vec2, 0, vec2.size(), std::greater<>());
  EXPECT_EQ(vec2, std::vector<int>());
}