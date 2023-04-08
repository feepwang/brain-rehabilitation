#ifndef BR_EXCHANGE_SORT_H_
#define BR_EXCHANGE_SORT_H_

#include <functional>
#include <vector>

namespace br {
inline namespace algorithms {

/**
 * @brief
 * Computational complexity: O(n^2)
 * Stability: Yes
 * differ from bubble sort, exchange sort compare the element at start with
 * other one to find the (smallest)
 * @tparam T
 * @tparam CompareFunctor
 * @param vec
 * @param functor
 */
template <typename T, class CompareFunctor = std::less<T>>
void ExchangeSort(std::vector<T>& vec, const CompareFunctor& functor = CompareFunctor()) {
  if (vec.empty()) {
    return;
  }

  for (size_t i = 0, end_index = vec.size() - 1; i < end_index; ++i) {
    //  first loop, place the smallest element to the first
    for (size_t j = i + 1; j <= end_index; ++j) {
      //  second loop, from end to start, compare and swap
      //  swap the element if functor return true
      if (functor(vec[j], vec[i])) {
        std::swap(vec[j], vec[i]);
      }
    }
  }
}

}  // namespace algorithms
}  // namespace br

#endif