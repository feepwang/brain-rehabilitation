#ifndef BR_INSERTION_SORT_H_
#define BR_INSERTION_SORT_H_

#include <functional>
#include <vector>

namespace br {

inline namespace algorithms {

/**
 * @brief
 * Computational complexity: O(n^2)
 * Stability: Yes
 * @tparam T
 * @tparam Comparer
 * @param vec
 * @param functor
 */
template <typename T, typename Comparer = std::less<T>>
void InsertionSort(std::vector<T>& vec, const Comparer& functor = Comparer()) {
  if (vec.empty()) {
    return;
  }

  for (size_t i = 1, end_index = vec.size() - 1; i <= end_index; ++i) {
    for (size_t j = i; j > 0; --j) {
      //  keep sub vector before i is sorted
      if (functor(vec[j], vec[j - 1])) {
        std::swap(vec[j], vec[j - 1]);
      } else {
        break;
      }
    }
  }
}

}  // namespace algorithms

}  // namespace br

#endif