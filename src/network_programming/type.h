/*
 * @file type.h
 * @brief type alias.
 * @author feep
 * @date 2023-05-20
 * @version 0.1.
 */

#ifndef BR_NP_TYPE_H_
#define BR_NP_TYPE_H_

namespace br {
namespace np {

#ifdef __linux__
using socket_handler_t = int;
#elifdef __WIN32

#endif

}  // namespace np
}  // namespace br

#endif