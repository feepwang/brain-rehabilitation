/*
 * @file quick_sort.h
 * @brief Quick Sort Algorithm
 * @author feep
 * @date 2023-04-23
 * @version 0.1.0
 */

#include <cstddef>
#include <functional>
#include <vector>

#ifndef BR_QUICK_SORT_H_
#define BR_QUICK_SORT_H_

namespace br {

inline namespace algorithms {

template <typename T, typename Comparer>
size_t ParitionLomutoVer(std::vector<T>& vec, size_t begin, size_t end, const Comparer& functor) {
  size_t middle = begin;
  size_t index = end - 1;
  const auto& pivot = vec[index];
  for (size_t i = begin; i < index; i++) {
    if (functor(vec[i], pivot)) {
      std::swap(vec[i], vec[middle++]);
    }
  }

  std::swap(vec[middle], vec[index]);
  return middle;
}

template <typename T, typename Comparer>
size_t ParitionHoareVer(std::vector<T>& vec, size_t begin, size_t end, const Comparer& functor) {
  const auto pivot = vec[begin + (end - begin) / 2];
  size_t left = begin, right = end - 1;
  while (true) {
    while (functor(vec[left], pivot)) {
      left++;
    }
    while (functor(pivot, vec[right])) {
      right--;
    }

    if (left >= right) {
      return left;
    }
    std::swap(vec[left], vec[right]);
  }
}

/**
 * @brief
 * Computational complexity: O(nlogn)
 * Stability: No
 * @tparam T
 * @tparam Comparer
 * @param vec
 * @param begin
 * @param end
 * @param functor
 */
template <typename T, typename Comparer = std::less<T>>
void QuickSort(std::vector<T>& vec, size_t begin, size_t end, const Comparer& functor = Comparer()) {
  if (end > vec.size() || begin > end || (end - begin) < 1) {
    return;
  }

  if ((end - begin) > 1) {
    auto mid = ParitionLomutoVer(vec, begin, end, functor);
    QuickSort(vec, begin, mid, functor);
    QuickSort(vec, mid + 1, end, functor);
  }
}

}  // namespace algorithms

}  // namespace br

#endif