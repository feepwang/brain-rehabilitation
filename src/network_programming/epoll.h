/*
 * @file epoll.h
 * @brief IO multiplexing, refer to https://man7.org/linux/man-pages/man7/epoll.7.html
 * @author feep
 * @date 2023-05-21
 * @version 0.1.0
 */

#ifndef BR_NP_EPOLL_H_
#define BR_NP_EPOLL_H_

#include <sys/epoll.h>
#include <sys/types.h>
#include <unistd.h>

#include <memory>
#include <set>
#include <vector>

#ifndef BR_NP_NOBLOCK
#define BR_NP_BLOCK
#endif

class Select {
 public:
  void BuildFDS();

  void SetTimeout(time_t second) {
    // timeout_.tv_sec = second;
    // timeout_.tv_usec = 0;
    timeout_ = second;
  }

  void AddFD(int fd) {
    static struct epoll_event event {};
    event.events = EPOLLIN | EPOLLRDHUP;
    event.data.fd = fd;
    epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &event);
  }

  int Run();

 private:
  int epoll_fd_;
  std::vector<struct epoll_event> recieved_;
  // struct timeval timeout_;
  int timeout_;
};

void DoProcess(int fd);

int Select::Run() {
  // static fd_set read_fds;
  // static fd_set write_fds;
  // static fd_set except_fds;

#ifdef BR_NP_BLOCK
  while (true) {
    int activated = epoll_wait(epoll_fd_, recieved_.data(), recieved_.capacity(), timeout_);
    if (activated == -1) {
      // perror("epoll");
    }
  }
  // return activated;
#endif
}

#endif