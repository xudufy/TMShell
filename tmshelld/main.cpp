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
  app.main();
  return 0;
}