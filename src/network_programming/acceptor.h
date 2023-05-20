/*
 * @file acceptor.h
 * @brief Acceptor, listen to generate new connection
 * @author feep
 * @date 2023-05-20
 * @version 0.1.0
 */

#ifndef BR_NP_ACCEPTOR_H_
#define BR_NP_ACCEPTOR_H_

#include <memory>

#include "type.h"

namespace br {
namespace np {

class Connection;

class Acceptor {
 public:
  //  get
  virtual socket_handler_t RawHandler() const noexcept;

  virtual std::unique_ptr<Connection> Accept() const = 0;

 private:
  socket_handler_t socket_;
};

}  // namespace np

}  // namespace br

#endif
