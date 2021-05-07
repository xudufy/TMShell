#pragma once
#include "../common/common.h"

#include <boost/bind/bind.hpp>
#include <boost/beast.hpp>
#include <boost/asio.hpp>

#include "VariableValue.h"

#include "InternalClock.h"

namespace tmshell {

namespace net = boost::asio;
namespace beast = boost::beast;
using namespace boost::beast;

class Session {
public:
  Session(net::io_context & ioc): ws(net::make_strand(ioc)) {}

  websocket::stream<tcp_stream> ws;
};

class MainLoop {
public:

  MainLoop():ioc(), tick_timer(ioc) {} 

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

};

} // namespace tmshell