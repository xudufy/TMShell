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

  void reset() {
    RefRealTime = Clock::now();
    RefPlayTime = RefRealTime;
    scaler = 1.0;
    LastTickRealTime = RefRealTime-std::chrono::seconds(1);
  }

  void setTime(TimePoint to);

  void setScaler(double to);  

  void tick(){
    std::cout<<"tick"<<std::endl;
  }

private:
  InternalClock() {}

public:
  InternalClock(InternalClock const&) = delete;
  void operator=(InternalClock const&) = delete;
  
private:
  TimePoint RefRealTime;
  TimePoint RefPlayTime;
  TimePoint LastTickRealTime;
  double scaler;

};

}

