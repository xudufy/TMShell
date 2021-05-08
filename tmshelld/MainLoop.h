#pragma once
#include "../common/common.h"

#include <boost/bind/bind.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>

#include "VariableValue.h"

#include "InternalClock.h"
#include "RegisterExecutor.h"

namespace tmshell {

namespace net = boost::asio;
namespace beast = boost::beast;
using namespace boost::beast;
using boost::system::error_code;
using net::ip::tcp;

class MainLoop;

//always use 'new' on this Class. The class will delete itself by delete this when the connection is closed.
class Session {
public:
  Session(net::io_context & ioc);
  Session(Session const & that) = delete;
  void operator=(Session const &) = delete;

  void start();

  void close();

  friend class MainLoop;

private:
  void read_handler(error_code const &e, std::size_t /*length*/);

  // we may allocate a const buffer for the write, and want to keep it until the handler is called.
  // buffer_need_delete is present for this purpose.
  // if buffer_need_delete is not nullptr, the pointer will be delete regardless of error_code.
  void write_handler(error_code const &e, std::size_t /*len_transferred*/, const void * buffer_need_delete = nullptr);

private:
  websocket::stream<tcp_stream> ws;
  RegisterExecutor run_env;
  beast::multi_buffer in_buffer;
  
};

class MainLoop {
public:
  MainLoop();
  MainLoop(MainLoop const &) = delete;
  void operator=(MainLoop const &) = delete;


  void stop_tick();

  int main();

private:
  void start_accept();

  void start_tick();

private:
  net::io_context ioc;
  net::basic_waitable_timer<Clock> tick_timer;
  tcp::acceptor acpr;
  Session * pendingSession;
};

} // namespace tmshell