/*
 * @file connection.h
 * @brief
 * @author feep
 * @date 2023-05-20
 * @version 0.1.0
 */

#ifndef BR_NP_CONNECTION_H_
#define BR_NP_CONNECTION_H_

#include <functional>

#include "type.h"

namespace br::np {
class Connection;
}

namespace std {
template <>
struct std::hash<br::np::Connection>;
}

namespace br {

namespace np {

class Connection {
  friend struct std::hash<Connection>;

 public:
  socket_handler_t RawHandler() const noexcept { return socket_; }

 private:
  socket_handler_t socket_;
};

}  // namespace np

}  // namespace br

namespace std {

template <>
struct std::hash<br::np::Connection> {
  size_t operator()(const br::np::Connection& conn) const noexcept {
    return std::hash<br::np::socket_handler_t>()(conn.socket_);
  }
};
}  // namespace std

#endif