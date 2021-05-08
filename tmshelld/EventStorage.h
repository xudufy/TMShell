#pragma once
#include "../common/common.h"
#include "VariableValue.h"

//TODO: full thread safe.
namespace tmshell {

class IEvent {
public:
  virtual ~IEvent() = default;
  virtual std::string to_string() = 0;
  int unique_id;
  std::string name;
  std::string action;
};

class TimerEvent : public IEvent {
public:
  virtual ~TimerEvent() = default;

  virtual std::string to_string(); 

  void update(TimePoint current, double scaler);  

  TimePoint nextTriggerTime;
  bool haveRepeat = false;
  TimePoint startTime, endTime = TimePoint::max();
  Duration period = std::chrono::seconds(1);

};

class StringEvent : public IEvent {
public:
  virtual ~StringEvent() = default;
  virtual std::string to_string();
  std::string signal;
};

class EventStorage{
public:
  static EventStorage& getInstance() {
    static EventStorage instance; 
    return instance;
  }

private:
  EventStorage() {}

public:
  EventStorage(EventStorage const&) = delete;
  void operator=(EventStorage const&) = delete;

public:
  int get_unique_id() {
    int t = next_unique_id++;
    return t;
  }

  void lock() {
    objmtx.lock();
  }

  void unlock() {
    objmtx.unlock();
  }

  void updateAllEvents(TimePoint current, double scaler);

public:
  std::list<StringEvent> str_events;
  std::list<TimerEvent> tm_events;
  std::list<TimerEvent> immediate_events;
  std::mutex objmtx;
  
private:
  std::atomic<int> next_unique_id = 1;
};

} // namespace tmshell