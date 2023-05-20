/*
 * @file reactor.h
 * @author feep
 * @date 2023-05-20
 * @version 0.1.0
 */

#ifndef BR_NP_REACTOR_H_
#define BR_NP_REACTOR_H_

#include <memory>

namespace br {

namespace np {

class Acceptor;

class Reactor {
 public:
  Reactor();
  ~Reactor();

  Reactor(const Reactor&) = delete;
  Reactor& operator==(const Reactor&) = delete;

  Reactor(Reactor&& reactor);

  Reactor& operator==(Reactor&& reactor);

  virtual void Serve() = 0;
  virtual void Stop() = 0;

 private:
  std::unique_ptr<Acceptor> acceptor_;
};

}  // namespace np

}  // namespace br

#endif