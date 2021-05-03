#pragma once

#ifdef ASSERT
#undef ASSERT
#endif 

#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <atomic>
#include <thread>
#include <string>
#include <list>
#include <sstream>

#define ASSERT(x, msg) do {\
  if (!(x)) { \
    std::cerr<<"Assertion failed:"<<#x<<":"<<(msg)<<std::endl; \
    exit(-1); \
  } \
} while (false)

#define LOG_IF_FALSE(x, msg) do {\
  if (!(x)) { \
    std::cerr<<"WARNING:"<<#x<<":"<<(msg)<<std::endl; \
  } \
} while (false)

#define WINVER 0x0601
#define _WIN32_WINNT 0x0601

#ifdef TEST_SERVER
#define TMSHELL_SERVICE_HOST "ufolya.xyz"
#define TMSHELL_SERVICE_PATH "/"
#define TMSHELL_SERVICE_PORT 55211
#else
#define TMSHELL_SERVICE_HOST "localhost"
#define TMSHELL_SERVICE_PATH "/"
#define TMSHELL_SERVICE_PORT 53127
#endif


#include "ParserInstance.h"