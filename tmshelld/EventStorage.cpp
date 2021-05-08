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

void TimerEvent::update(TimePoint current, double scaler) {
  if (!haveRepeat) {
    return;
  }
  ASSERT(period!=Duration(0), "period cannot be 0");
  
  Duration durCur = current.time_since_epoch();
  Duration durStart = startTime.time_since_epoch();
  Duration durEnd = endTime.time_since_epoch();

  if (scaler > 0) {
    if (durEnd < durCur) {
      nextTriggerTime = TimePoint::max();
      return;
    }

    if (durStart <= durCur) {
      int64_t m = (durCur - durStart) / period;
      nextTriggerTime = startTime + (m + 1) * period;
      if (nextTriggerTime > endTime) {
        nextTriggerTime = TimePoint::max();
      }
      return;
    } else {
      nextTriggerTime = startTime;
      if (nextTriggerTime > endTime) {
        nextTriggerTime = TimePoint::max();
      }
      return;
    }

  } else {
    if (durStart > durCur) {
      nextTriggerTime = TimePoint::max();
      return;
    } 

    if (durCur > durEnd) {
      int64_t m = (durEnd - durStart) / period;
      nextTriggerTime = m * period + startTime;
      if (m >= 0) {
        nextTriggerTime = m * period + startTime;
      } else {
        nextTriggerTime = TimePoint::max();
      }
      return;
    } else {
      int64_t m = (durCur - durStart) / period;
      if (((durCur-durStart) % period).count() == 0) {
        m = m - 1;
      }
      if (m >= 0) {
        nextTriggerTime = m * period + startTime;
      } else {
        nextTriggerTime = TimePoint::max();
      }
      return;
    }

  }
  
}

void EventStorage::updateAllEvents(TimePoint current, double scaler) {
  lock();
  for (auto iter = tm_events.begin(); iter != tm_events.end(); ++iter) {
    iter->update(current, scaler);
  }
  unlock();
}


} // namespace tmshell