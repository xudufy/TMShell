#include "VariableValue.h"
#include "MainLoop.h"

#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>

using namespace std;
using namespace tmshell;

int main() {
  MainLoop app;
  std::thread work([&app](){app.main();});
  std::this_thread::sleep_for(std::chrono::seconds(10));
  app.stop_tick();
  work.join();
  return 0;
}