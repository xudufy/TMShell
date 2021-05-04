#pragma once
#include "../common/common.h"
#include "VariableValue.h"


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

  TimePoint nextTriggerTime;
  bool haveRepeat;
  TimePoint startTime, endTime;
  Duration period;

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
    objlock.lock();
  }

  void unlock() {
    objlock.unlock();
  }

public:
  std::list<StringEvent> str_events;
  std::list<TimerEvent> tm_events;
  std::list<TimerEvent> immediate_events;
  std::mutex objlock;
  
private:
  std::atomic<int> next_unique_id = 1;
};

} // namespace tmshell