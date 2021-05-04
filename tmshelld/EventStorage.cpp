#include "EventStorage.h"
namespace tmshell {

std::string TimerEvent::to_string() {
    std::string out = "id" +std::to_string(unique_id) + '\t' + "name:" + name + "\n";
    if (haveRepeat) {
      auto priodic = StructValue::ofPriodic(startTime, endTime, period);
      out += priodic.to_string();
    } else {
      out += tmshell::to_string(nextTriggerTime);
    }
    out += "\n action = " + action + "\n";
    return out;
}

std::string StringEvent::to_string() {
  std::string out = "id" +std::to_string(unique_id) + '\t' + "name:" + name + "\n";
  out += "signal:" + signal + "\n";
  out += "action = " + action + "\n";
  return out;
}

} // namespace tmshell