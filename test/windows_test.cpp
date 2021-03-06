#include "../common/common.h"
#include "../tmshelld/VariableValue.h"
#include "../tmshelld/BuiltinFunc.h"
#include "../tmshelld/ActionExecutor.h"

using namespace std;
using namespace tmshell;
using namespace std::chrono;

int main() {
  ActionExecutor e;
  BuiltinFunc a(&e);

  for (int i=0; i<5; i++) {
    a.alert("haha");
    std::this_thread::sleep_for(seconds(1));
  }

  a.shell_open("C:/Windows/regedit.exe").get();
  cout<<e.log<<endl;

  std::this_thread::sleep_for(seconds(20));

  return 0;
}