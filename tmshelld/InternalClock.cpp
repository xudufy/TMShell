#include "InternalClock.h"
#include "EventStorage.h"
#include "ActionExecutor.h"

namespace tmshell {

void InternalClock::reset() {
  TimePoint rpt_copy;
  double scaler_copy;
  {
    std::lock_guard<std::mutex> lock(objmtx);
    RefRealTime = Clock::now();
    RefPlayTime = RefRealTime;
    scaler = 1.0;
    LastTickRealTime = RefRealTime-std::chrono::seconds(1);

    // because we have not tick on this second. So we update the time events
    // with the timepoint 1 second ago. 
    rpt_copy = LastTickRealTime; 
    scaler_copy = scaler;
  }
  
  EventStorage::getInstance().updateAllEvents(rpt_copy, scaler_copy);
}

void InternalClock::setTime(TimePoint to) {
  TimePoint rpt_copy;
  double scaler_copy;
  {
    std::lock_guard<std::mutex> lock(objmtx);
    RefRealTime = Clock::now();
    RefPlayTime = to;
    rpt_copy = RefPlayTime;
    scaler_copy = scaler;
  }
  EventStorage::getInstance().updateAllEvents(rpt_copy, scaler_copy);
}

void InternalClock::setScaler(double to) {
  TimePoint rpt_copy;
  double scaler_copy;
  {
    std::lock_guard<std::mutex> lock(objmtx);
    scaler = to;
    rpt_copy = RefPlayTime;
    scaler_copy = scaler;
  }
  EventStorage::getInstance().updateAllEvents(rpt_copy, scaler_copy);
}

TimePoint InternalClock::toPlaytime(TimePoint rt, TimePoint refRT, TimePoint refPT, double scaler) {
  return refPT + duration_cast<Duration>((rt-refRT)*scaler);
}

void InternalClock::tick(){
  TimePoint lower_copy, upper_copy, cur_copy;
  double scaler_copy;
  
  {
    std::lock_guard<std::mutex> lock(objmtx);
    TimePoint lastTickPlayTime = toPlaytime(LastTickRealTime, RefRealTime, RefPlayTime, scaler);
    TimePoint thisTickRealTime = Clock::now();
    TimePoint thisTickPlayTime = toPlaytime(thisTickRealTime, RefRealTime, RefPlayTime, scaler);

    if (thisTickPlayTime < lastTickPlayTime) {
      lower_copy = thisTickPlayTime;
      upper_copy = lastTickPlayTime;
    } else {
      lower_copy = lastTickPlayTime;
      upper_copy = thisTickPlayTime;
    }

#ifdef TMSHELLD_OUTPUT_TO_CONSOLE
    std::cout<<"Internal time:"<<to_string(thisTickPlayTime)<<std::endl;
#endif

    LastTickRealTime = thisTickRealTime;
    cur_copy = thisTickPlayTime;
    scaler_copy = scaler;
  }


//---------------------- get events---------------
  EventStorage::getInstance().lock();

  EventStorage & evstore = EventStorage::getInstance();
  using namespace std;
  vector<string> actions;
  vector<int> uids;
  for (auto iter = evstore.tm_events.begin(); iter!= evstore.tm_events.end(); ++iter) {
    if ((iter->nextTriggerTime > lower_copy 
          && iter->nextTriggerTime < upper_copy
          ) || iter->nextTriggerTime == cur_copy ) {

      actions.push_back(iter->action);
      uids.push_back(iter->unique_id);
    }
    iter->update(cur_copy, scaler);
  }

  for (auto iter = evstore.immediate_events.begin(); iter != evstore.immediate_events.end(); ++iter) {
    actions.push_back(iter->action);
    uids.push_back(iter->unique_id);
  }
  evstore.immediate_events.clear();

  EventStorage::getInstance().unlock();
//----------------------get events end------------

  for (int i=0; i<actions.size(); i++) {
    string out;
    try {
      out = runAction(actions[i], uids[i]);
    } catch (ExecutionError const & e) {
      out = e.what();
    }
#ifdef TMSHELLD_OUTPUT_TO_CONSOLE
    std::cout << out << std::endl;
#endif    
  }

}

TimePoint InternalClock::getLastTickPlayTime() {
  return toPlaytime(LastTickRealTime, RefRealTime, RefPlayTime, scaler);
}

double InternalClock::getScaler() {
  return scaler;
}

} // namespace tmshell