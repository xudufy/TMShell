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
using net::ip::tcp;

class Session {
public:
  Session(net::io_context & ioc): ws(net::make_strand(ioc)) {}

  bool isClosed() {
    return !ws.is_open()
  }

  websocket::stream<tcp_stream> ws;
  RegisterExecutor run_env;
};

class MainLoop {
public:

  MainLoop():
    ioc(), 
    tick_timer(ioc),
    acpr(ioc, tcp::endpoint(tcp::v4(), TMSHELL_SERVICE_PORT)) 
    {} 

  int main() {
    tick_timer.expires_after(std::chrono::seconds(1));
    tick_timer.async_wait(boost::bind(tick_handler, net::placeholders::error, &tick_timer));


    ioc.run();
    return 0;
  }

  static void tick_handler(
      const boost::system::error_code& e, 
      net::basic_waitable_timer<Clock>* tick_timer
    ) {
    
    if (e != net::error::operation_aborted) {
      tick_timer->expires_after(std::chrono::seconds(1));
      InternalClock::getInstance().tick();
      tick_timer->async_wait(boost::bind(tick_handler, net::placeholders::error, tick_timer));
    }
  
  }

  void stop_tick() {
    tick_timer.expires_at(Clock::now() - std::chrono::seconds(10));
  }

private:
  net::io_context ioc;
  net::basic_waitable_timer<Clock> tick_timer;
  tcp::acceptor acpr;
};

} // namespace tmshell