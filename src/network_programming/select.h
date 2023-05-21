/*
 * @file select.h
 * @brief select IO multiplexing, refer to https://man7.org/linux/man-pages/man2/select.2.html
 * @author feep
 * @date 2023-05-20
 * @version 0,1,0
 */

#ifndef BR_NP_SELECT_H_
#define BR_NP_SELECT_H_

#include <string.h>
#include <sys/errno.h>
#include <sys/select.h>
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
    timeout_.tv_sec = second;
    timeout_.tv_usec = 0;
  }

  std::set<int> allActivated() {
    std::set<int> result;
    for (int fd : register_fds_) {
      if (FD_ISSET(fd, &read_fds_) || FD_ISSET(fd, &write_fds_) || FD_ISSET(fd, &except_fds_))
      {

      }
    }
    return result;
  }
  int Run();

 private:
  fd_set read_fds_;
  fd_set write_fds_;
  fd_set except_fds_;

  int max_fd_;
  std::set<int> register_fds_;
  struct timeval timeout_;
};

void DoProcess(int fd);

int Select::Run() {
  // static fd_set read_fds;
  // static fd_set write_fds;
  // static fd_set except_fds;

#ifdef BR_NP_BLOCK
  while (true) {
    FD_ZERO(&read_fds_);
    FD_ZERO(&write_fds_);
    FD_ZERO(&except_fds_);

    //  set fds
    //  content

    int activated = select(max_fd_ + 1, &read_fds_, &write_fds_, &except_fds_, &timeout_);
    if (activated == -1) {
      // perror("select");
    }
    std::set<int> fds = allActivated();
    for (auto fd : fds) {
      DoProcess(fd);
    }
  }
  // return activated;
#endif
}

#endif
