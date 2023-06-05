/*
 * @file noncopyable.h
 * @brief nocopable
 * @author feep
 * @date 2023-06-05
 * @version 0.1.0
 */

namespace br {

class Noncopyable {
  public:
  Noncopyable() = default;
  virtual ~Noncopyable() = default;

  //  disable copy constructor/ copy assigner operator
  Noncopyable(const Noncopyable&) = delete;
  Noncopyable& operator=(const Noncopyable&) = delete;

  //  enable move
  Noncopyable(Noncopyable&&) = default;
  Noncopyable& operator=(Noncopyable&&) = default;
};

}  // namespace br