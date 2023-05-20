#include "reactor.h"

#define BR_ENABLE_SELECT
#ifdef BR_ENABLE_SELECT
#include <sys/select.h>
#include <unistd.h>
#endif

#include "acceptor.h"
#include "connection.h"

namespace br {

namespace np {

#ifdef BR_ENABLE_SELECT

void Reactor::Serve() {}

#elifdef BR_ENABLE_EPOLL

#elifdef BR_ENABLE_IO_URING

#endif

}  // namespace np

}  // namespace br