/*
 * @file merge_sort.h
 * @brief Merge Sort
 * @author feep
 * @date 2023-04-12
 * @version 0.1.0
 */

#ifndef BR_MERGE_SORT_H_
#define BR_MERGE_SORT_H_

#include <functional>
#include <vector>

namespace br {
inline namespace algorithms {

template <typename T, typename Comparer = std::less<T>>
void Merge(std::vector<T>& vec, std::vector<T>& tmp, size_t left, size_t mid, size_t right,
           const Comparer& functor = Comparer()) {
  size_t i = left;
  size_t j = mid;
  size_t k = left;
  while (i < mid && j < right) {
    if (functor(vec[i], vec[j])) {
      tmp[k++] = vec[i++];
    } else {
      tmp[k++] = vec[j++];
    }
  }

  while (i < mid) {
    tmp[k++] = vec[i++];
  }
  while (j < right) {
    tmp[k++] = vec[j++];
  }
  for (size_t i = left; i < right; ++i) {
    vec[i] = tmp[i];
  }
}

template <typename T, typename Comparer = std::less<T>>
void MergeSort(std::vector<T>& vec, size_t begin, size_t end, std::vector<T>& tmp,
               const Comparer& functor = Comparer()) {
  if ((end - begin) > 1) {
    size_t mid = (begin + end) / 2;
    MergeSort(vec, begin, mid, tmp, functor);
    MergeSort(vec, mid, end, tmp, functor);
    Merge(vec, tmp, begin, mid, end, functor);
  }
}

}  // namespace algorithms
}  // namespace br
#endif