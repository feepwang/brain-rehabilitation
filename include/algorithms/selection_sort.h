//  bubble_sort

#ifndef BR_SELECTION_SORT_H_
#define BR_SELECTION_SORT_H_

#include <functional>
#include <vector>

namespace br {
inline namespace algorithms {

/**
 * @brief
 * Computational complexity: O(n^2)
 * Stability: No
 * differ from exchange sort, selection sort only exchange the min value
 * @tparam T
 * @tparam Comparer
 * @param vec
 * @param functor
 */
template <typename T, class Comparer = std::less<T>>
void SelectionSort(std::vector<T>& vec, const Comparer& functor = Comparer()) {
  if (vec.empty()) {
    return;
  }

  std::size_t min_index{};
  for (std::size_t i = 0, end_index = vec.size() - 1; i < end_index; ++i) {
    min_index = i;
    for (std::size_t j = i + 1; j <= end_index; ++j) {
      if (functor(vec[j], vec[min_index])) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(vec[i], vec[min_index]);
    }
  }
}

}  // namespace algorithms
}  // namespace br

#endif
