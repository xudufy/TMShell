#include "../common/common.h"
#include "../tmshelld/VariableValue.h"
#include "../tmshelld/BuiltinFunc.h"
#include "../tmshelld/ActionExecutor.h"

using namespace std;
using namespace tmshell;
using namespace std::chrono;

int main() {

  std::vector<std::string> inputs{
    "<.>", ">>15m", "15m+13s",
    "{let k=10m; <.> @ k}",
    "log(<.>)", "{shell_open(\"C:/Windows/regedit.exe\")}"
  };

  for (auto in: inputs){
    try {
      runAction(in);
    } catch (ExecutionError const & e) {
      cerr << e.what() << endl;
      throw;
    }
  }

  std::this_thread::sleep_for(seconds(20)); //let shell_open finish.
  
  return 0;
}