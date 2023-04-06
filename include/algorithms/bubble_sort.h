//  bubble_sort

#ifndef BR_BUBBLE_SORT_H_
#define BR_BUBBLE_SORT_H_

#include <functional>
#include <vector>

namespace br {
inline namespace algorithms {

/**
 * @brief
 *
 * @tparam T
 * @tparam Comparer
 * @param vec
 * @param functor
 */
template <typename T, class Comparer = std::less<T>>
void BubbleSort(std::vector<T>& vec, Comparer functor = Comparer()) {
  if (vec.empty()) {
    return;
  }

  for (size_t i = 0, end_index = vec.size() - 1; i <= end_index; ++i) {
    //  first loop, place the smallest element to the first
    for (size_t j = end_index; j > i; --j) {
      //  second loop, from end to start, compare and swap
      //  swap the element if functor return true
      if (functor(vec[j], vec[j - 1])) {
        std::swap(vec[j], vec[j - 1]);
      }
    }
  }
}

}  // namespace algorithms
}  // namespace br

#endif
