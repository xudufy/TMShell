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
    cout << to_string(chrono::system_clock::now() - cur.get()) <<endl;
    cur.set(chrono::system_clock::now());
    cout <<cur.getTypeName()<< cur.get().time_since_epoch().count() << endl;
    
    cout <<cur.to_string() << endl;
    cout << "duration: ";
    std::string input;
    input = "1w3d2m5s8h";
    cout << to_string(to_Duration(input))<<endl;
    cout << "tp";
    cin >> input;
    cout << to_string(to_TimePoint(input)) << endl; 

    StructValue c = StructValue::ofPriodic(chrono::system_clock::now(), TimePoint::max(), to_Duration("10s"));
    cout << to_string(c)<<endl;

    this_thread::sleep_for(chrono::seconds(1));
  }
}