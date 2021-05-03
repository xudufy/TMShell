#pragma once
#include "../common/common.h"

namespace tmshell {

class JumpOutSignal: public std::exception {
};

class ExecutionError: public std::runtime_error {
public:
  explicit ExecutionError(const std::string& msg): std::runtime_error(msg) {}
  explicit ExecutionError(const char * msg): std::runtime_error(msg) {} 
};

} // namespace tmshell