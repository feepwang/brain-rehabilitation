/*
 * @file shell_sort.h
 * @brief ShellSort
 * @author feep
 * @date 2023-04-11
 * @version 0.1.0
 */

#ifndef BR_SHELL_SORT_H_
#define BR_SHELL_SORT_H_

#include <functional>
#include <vector>

namespace br {

inline namespace algorithms {

/**
 * @brief
 * Optimized version from Insertion Sort, using gap to reduce the number of swap operations.
 * Computational complexity: O(n^(4/3)), nlog(n) at best, O(n^2) at worst
 * Stability: No
 * @tparam T
 * @tparam Comparer
 * @param vec
 * @param functor
 */
template <typename T, typename Comparer = std::less<T>>
void ShellSort(std::vector<T>& vec, const Comparer& functor = Comparer()) {
  if (vec.empty()) {
    return;
  }

  for (size_t gap = vec.size() / 2; gap > 0; gap /= 2) {
    for (size_t i = gap, end_index = vec.size() - 1; i <= end_index; ++i) {
      for (size_t j = i; j >= gap; j -= gap) {
        if (functor(vec[j], vec[j - gap])) {
          std::swap(vec[j], vec[j - gap]);
        } else {
          break;
        }
      }
    }
  }
}

}  // namespace algorithms

}  // namespace br

#endif