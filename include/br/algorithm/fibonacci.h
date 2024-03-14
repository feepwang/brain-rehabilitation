#ifndef _BR_ALGORITHM_FIBONACCI_H_
#define _BR_ALGORITHM_FIBONACCI_H_

#include <type_traits>

namespace br {
namespace al {

template <typename Integer,
          typename = std::enable_if<std::is_integral<Integer>::value>>
Integer Fibonacci(std::size_t n) {
  if (n <= 1) {
    return n;
  }
  return Fibonacci<Integer>(n - 1) + Fibonacci<Integer>(n - 2);
}

}  // namespace al
}  // namespace br

#endif
