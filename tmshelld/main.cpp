#include "VariableValue.h"

#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>

using namespace std;
using namespace tmshell;

int main() {
  TimePointValue cur(chrono::system_clock::now());

  while (true) {
    cur.set(chrono::system_clock::now());
    cout <<cur.getTypeName()<< cur.get().time_since_epoch().count() << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
}