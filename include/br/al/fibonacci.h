#ifndef _BR_ALGORITHM_FIBONACCI_H_
#define _BR_ALGORITHM_FIBONACCI_H_

#include <cassert>
#include <limits>
#include <stdexcept>
#include <type_traits>

#include "fmt/core.h"

namespace br {
namespace al {

// pre-declaration
template <typename Integer>
Integer Fibonacci(Integer n);

template <typename Integer>
class FibonacciImpl {
  friend Integer Fibonacci<>(Integer n);
  static_assert(std::is_integral<Integer>::value,
                "return value must be integral");

  FibonacciImpl() = default;
  Integer operator()(std::size_t n) { return Implement(n); }

  Integer Implement(std::size_t n) {
    if (n <= 1) {
      return n;
    }
    Integer a = 0;
    Integer b = 1;
    static Integer max = std::numeric_limits<Integer>::max();
    for (std::size_t i = 1; i < n; i++) {
      if (a > max - b) {
        throw std::overflow_error(fmt::format(
            "variable will overflow in fibonacci calculation with input ({})",
            n));
      }
      a = b + a;
      std::swap(a, b);
    }
    return b;
  }
};

template <typename Integer>
std::enable_if_t<std::is_integral<Integer>::value, Integer> Fibonacci(
    Integer n) {
  assert(n >= 0);

  auto tmp = FibonacciImpl<Integer>()(n);
  return tmp;
}

}  // namespace al
}  // namespace br

#endif
