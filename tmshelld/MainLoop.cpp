#include "MainLoop.h"

namespace tmshell {

Session::Session(net::io_context & ioc): ws(net::make_strand(ioc)) {}

void Session::start() {
  ws.binary(true);

  ws.async_accept([=](error_code const & e){
    this->write_handler(e, 0);
  });
}

void Session::read_handler(error_code const &e, std::size_t /*length*/) {
  if (e) {
    this->close();
    return;
  }

  std::string in = beast::buffers_to_string(in_buffer.data());
  in_buffer.clear();
  
  std::string out = in;
  try {
    out = runRegister(in, &run_env);
  } catch (ExecutionError const & e) {
    out = e.what();
  }

  const std::string* const_out = new const std::string(out);
  
  ws.async_write(net::buffer(*const_out), [=](error_code const &e, std::size_t len){
    this->write_handler(e, len, const_out);
  });
}

void Session::write_handler(error_code const &e, std::size_t /*len_transferred*/, const void * buffer_need_delete) {
  
  if (buffer_need_delete != nullptr) {
    delete buffer_need_delete;
  }

  if (e) {
    this->close();
    return;
  }

  in_buffer.clear();
  ws.async_read(in_buffer, [=](error_code const & e, std::size_t length){
    this->read_handler(e, length);
  });
}

void Session::close() {

  try {
    ws.close("close called in server.");
  } catch (std::exception const & e) {
#ifdef TMSHELLD_OUTPUT_TO_CONSOLE
    LOG_IF_FALSE(false, e.what());
#endif
  }

  delete this;
}

MainLoop::MainLoop():
  ioc(), 
  tick_timer(ioc),
  acpr(net::make_strand(ioc), 
    tcp::endpoint(tcp::v4(), TMSHELL_SERVICE_PORT)
  ) {} 


void MainLoop::start_accept() {
  pendingSession = new Session(ioc);
  acpr.async_accept(
    beast::get_lowest_layer(pendingSession->ws).socket(), 
    [=](error_code const & e){
      if (!e) {
        this->pendingSession->start();
        this->start_accept();
      }
    }
  );
}

void MainLoop::start_tick() {
  tick_timer.expires_after(std::chrono::seconds(1));
  
  tick_timer.async_wait(
    [=](const error_code& e){
      if (e != net::error::operation_aborted) {
        InternalClock::getInstance().tick();
        this->start_tick();
      }
    }
  );

}

void MainLoop::stop_tick() {
  tick_timer.expires_at(Clock::now() - std::chrono::seconds(10));
}

int MainLoop::main() {
  start_tick();
  start_accept();

  std::thread t1([this](){this->ioc.run();});
  std::thread t2([this](){this->ioc.run();});
  ioc.run();
  t1.join();
  t2.join();
  return 0;
}


} // namespace tmshell