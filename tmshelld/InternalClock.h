#pragma once
#include "../common/common.h"

#include "VariableValue.h"


namespace tmshell {

class InternalClock{
public:
  static InternalClock& getInstance() {
    static InternalClock instance; 
    return instance;
  }

  void reset();

  void setTime(TimePoint to);

  void setScaler(double to);

  //not thread safe. Must lock on objmtx to stop the world.
  //if one need to stop the world, the lock order is:
  //lock(InternalClock);
  //lock(EventStorage);
  //lock(GlobalScope);
  TimePoint getLastTickPlayTime();
  double getScaler();

  void tick();

private:
  InternalClock() {
    RefRealTime = Clock::now();
    RefPlayTime = RefRealTime;
    scaler = 1.0;
    LastTickRealTime = RefRealTime;
  }

  TimePoint toPlaytime(TimePoint rt, TimePoint refRT, TimePoint refPT, double scaler);

public:
  InternalClock(InternalClock const&) = delete;
  void operator=(InternalClock const&) = delete;
  
private:
  TimePoint RefRealTime;
  TimePoint RefPlayTime;
  TimePoint LastTickRealTime;
  double scaler;

public:
  std::mutex objmtx;

};

}

