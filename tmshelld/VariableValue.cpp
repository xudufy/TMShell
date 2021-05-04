#include "VariableValue.h"
#include "ExecutionError.h"
#include "WindowsSubsys.h" // for utf8 support.

#include <ctime>
#include <sstream>
#include <array>


namespace tmshell{

const char* IVariableValue::BaseVar[] = {"int", "bool", "string", "time_point",
                                                "duration", "periodic"};

IVariableValue::IVariableValue(const std::string& type):_typeName(type) {
}

StructValue::StructValue(const std::string& typeName)
  :IVariableValue(typeName),
  _field()
{
}


StructValue::StructValue(const StructValue& that)
  : IVariableValue(that.getTypeName()),
  _field()
{
  for (auto iter = that._field.begin(); iter!= that._field.end(); ++iter) {
    std::string k = iter->first;
    IVariableValue* v = iter->second.get();
    this->_field[k] = v->copy();
  }
}

StructValue::StructValue(StructValue&& that):
  IVariableValue(that.getTypeName()),
  _field(std::move(that._field))
{
}

StructValue::~StructValue() {
  _field.clear();
}

StructValue& StructValue::operator=(const StructValue& that) {
  this->IVariableValue::operator=(that);
  _field.clear();
  for (auto iter = that._field.begin(); iter!= that._field.end(); ++iter) {
    std::string k = iter->first;
    IVariableValue* v = iter->second.get();
    this->_field[k] = v->copy();
  }
  return *this;
}

StructValue& StructValue::operator=(StructValue&& that) {
  this->IVariableValue::operator=(that);
  _field=std::move(that._field);
  return *this;
}

StructValue StructValue::ofPriodic(TimePoint start, TimePoint end, Duration repeat) {
  StructValue newobj(IVariableValue::BaseVar[4]);
  newobj.addField("start", TimePointValue(start));
  newobj.addField("end", TimePointValue(end));
  newobj.addField("repeat", DurationValue(repeat));
  return newobj;
}

IVariableValue* StructValue::getField(const std::string& fieldName) const {
  if (_field.count(fieldName) == 0) {
    throw ExecutionError("fieldname " + fieldName + " not found.");
  } else {
    return _field.at(fieldName).get();
  }
}

bool StructValue::checkField(const std::string& fieldName) const {
  return _field.count(fieldName) > 0;
}

bool StructValue::addField(const std::string& fieldName, const IVariableValue & value) {
  if (checkField(fieldName)) {
    return setField(fieldName, value);
  } else {
    _field[fieldName] = value.copy();
  }
  return true;
}

bool StructValue::setField(const std::string& fieldName, const IVariableValue & value) {
  if (!checkField(fieldName)) {
    return false;
  } else if (_field[fieldName]->getTypeName() != value.getTypeName()) {
    // once a field is set, its type should not be changed.
    throw ExecutionError("field or variable \"" + fieldName + "\" is type " +
      _field[fieldName]->getTypeName() + " but assigned a value of type " + 
      value.getTypeName()
    );
  } else {
    _field[fieldName] = value.copy();
  }
  return true;
}

std::string to_string(TimePoint const & tp) {
  using namespace std::chrono;

  //special case for TimePoint::max()
  if (tp == TimePoint::max()) {
    return "<forever>";
  }

  auto posix_time = system_clock::to_time_t(tp);
  char buf[256];
  tm local;
  auto err = localtime_s(&local, &posix_time);
  if (err != 0) {
    throw ExecutionError("unsupported time point");
  }
  strftime(buf, 255, "%m/%d/%Y %a %H:%M:%S", &local);
  return buf;
}



TimePoint to_TimePoint(std::string const & in) {
  using namespace std::chrono;
  constexpr const size_t & npos = std::string::npos;
  
  tm to_tm;

//default values
  to_tm.tm_isdst = -1;
  to_tm.tm_sec = 0;
  to_tm.tm_mday = -1;
  to_tm.tm_year = -1;
  to_tm.tm_mon = -1;
  to_tm.tm_wday = -1;

  const auto Tpos = in.find_first_of("Tt");
  const auto Dpos = in.find_first_of("Dd");

  std::string time_part;
  if (Dpos == npos && Tpos != npos) { //if have date part. Cannot use Tpos!=npos only because 0:0DTue can hack it.
    
    
    auto in_day = in.substr(0, Tpos);
    time_part = in.substr(Tpos+1);

    int numbers[3] = {-1, -1, -1};
    for (int i=2; i>=0; i--) {
      auto colon_pos = in_day.find_last_of(":");
      if (colon_pos != npos) {
        auto num_part = in_day.substr(colon_pos+1);
        in_day = in_day.substr(0, colon_pos);
        std::stringstream ss(num_part);
        ss>>numbers[i];
      } else {
        std::stringstream ss(in_day);
        ss>>numbers[i];
        break;
      }
    }

    if (numbers[0] != -1) {
      numbers[0] -= 1900; //year start from 1900.
    }
    if (numbers[1] != -1) {
      numbers[1] -= 1; //month start from 00.
    }

    to_tm.tm_year = numbers[0];
    to_tm.tm_mon = numbers[1];
    to_tm.tm_mday = numbers[2];

  } else if (Dpos != npos) {
    auto wday_part = in.substr(Dpos+1);
    std::transform(wday_part.begin(), wday_part.end(), wday_part.begin(),
    [](unsigned char c){ return (char)std::tolower(c); });

    time_part = in.substr(0, Dpos);
    constexpr const static char * weekdays[] = {
      "sun", "mon", "tue", "wed", "thu", "fri", "sat"
    };

    for (int i=0; i<7; i++) {
      if (wday_part == weekdays[i]) {
        to_tm.tm_wday = i;
        break;
      }
    }
  } else {
    time_part = in;
  }

  int numbers[3] = {0, 0, 0};
  for (int i=0; i<3; i++) {
    auto colon_pos = time_part.find_first_of(":");
    if (colon_pos != npos) {
      auto num_part = time_part.substr(0, colon_pos);
      time_part = time_part.substr(colon_pos+1);
      std::stringstream ss(num_part);
      ss>>numbers[i];
    } else {
      std::stringstream ss(time_part);
      ss>>numbers[i];
      break;
    }
  }

  to_tm.tm_hour = numbers[0];
  to_tm.tm_min = numbers[1];
  to_tm.tm_sec = numbers[2];

  auto posix_time = system_clock::to_time_t(system_clock::now());
  tm now_tm;
  localtime_s(&now_tm, &posix_time);

  find_next_occurance(now_tm, to_tm);
  
  return system_clock::from_time_t(mktime(&to_tm));

}

void find_next_occurance(tm now_tm, tm & to_tm) {
  if (to_tm.tm_year != -1) {
    return;
  }

  auto extract_tm = [] (tm to_tm) -> std::array<int, 6> {
    return {
      to_tm.tm_year,
      to_tm.tm_mon,
      to_tm.tm_mday,
      to_tm.tm_hour,
      to_tm.tm_min,
      to_tm.tm_sec
    };
  };

  auto compose_tm = [] (std::array<int, 6> v) -> tm {
    tm to_tm;
    to_tm.tm_year = v[0];
    to_tm.tm_mon = v[1];
    to_tm.tm_mday = v[2];
    to_tm.tm_hour = v[3];
    to_tm.tm_min = v[4];
    to_tm.tm_sec = v[5];
    return to_tm;
  };
  
  auto unified = extract_tm(to_tm);

  auto uninow = extract_tm(now_tm);
  
  if (to_tm.tm_wday == -1) {
    int i = 0;
    while (unified[i] == -1) {
      unified[i] = uninow[i];
      i++;
    }

    int compare_result = 0;
    for (int j=i; j<6; j++) {
      if (unified[j] < uninow[j]) {
        compare_result = -1;
        break;
      } else if (unified[j] > uninow[j]) {
        compare_result = 1;
        break;
      }
    }

    if (compare_result <= 0 && i!=0) {
      unified[i - 1] ++;
    }

    to_tm = compose_tm(unified);

    return;

  } else {

    bool needAdjust = true;
    if (to_tm.tm_wday == now_tm.tm_wday) {
      int compare_result = 0;
      
      for (int i = 3; i<6; i++) {
        if (unified[i] < uninow[i]) {
          compare_result = -1;
          break;
        } else if (unified[i] > uninow[i]) {
          compare_result = 1;
          break;
        }
      }
      
      if (compare_result > 0) {
        needAdjust = false;
      }
    }


    to_tm.tm_year = now_tm.tm_year;
    to_tm.tm_mon = now_tm.tm_mon;
    to_tm.tm_mday = now_tm.tm_mday;

    if (needAdjust) {
      int day_inteval = (to_tm.tm_wday + 7 - now_tm.tm_wday) % 7;
      if (day_inteval == 0) day_inteval = 7;
      to_tm.tm_mday += day_inteval;
    }
  }
  
  return;
}

std::string to_string(Duration const & dur) {
  auto c = duration_cast<seconds>(dur).count();
  bool minus = c<0;
  if (minus) {
    c = -c;
  }
  auto d = c / 86400;
  c = c % 86400;
  auto h = c / 3600;
  c = c % 3600;
  auto m = c / 60;
  auto s = c % 60;

  char buf[256];
  if (minus) {
    d = -d;
  }
  snprintf(buf, 255, "%I64dd%I64dh%I64dm%I64ds", d, h, m, s);

  return buf;
}

Duration to_Duration(std::string const & in) {
  std::string ___ = in;
  auto __ = ___.find_first_of("wdhms");
  auto _ = 0;
  while (~__) {
    auto ____ = ___[__];
    auto _____ = 0;
    sscanf(___.substr(0,__).c_str(), "%d", &_____);
    ___ = ___.substr(__+1);
    __ = ___.find_first_of("wdhms");
    switch (____)
    {
      case 'w':
        _____*= 7;
      case 'd':
        _____*= 24;
      case 'h':
        _____*= 60;
      case 'm':
        _____*= 60;
      break;  
    }
    _ += _____;
  }
  return duration_cast<Duration>(std::chrono::seconds(_));
}

std::string to_string(StructValue const & sv) {
  std::string out = "{";
  for (auto iter = sv._field.begin(); iter!= sv._field.end(); ++iter) {
    out += iter->first + "=" + iter->second->to_string() + ", \n";
  }
  out += "}";
  return out;
}

std::string unescape_string(std::string const & in) {
  auto firstQuote = in.find_first_of("\"");
  auto lastQuote = in.find_last_of("\"");
  std::string temp_in = in;
  if (lastQuote > firstQuote) {
    temp_in = in.substr(firstQuote+1, lastQuote-firstQuote-1);
  }
  if (temp_in.size() == 0) {
    return temp_in;
  }

  std::wstring temp = utf8_to_wchar(temp_in);
  std::wstring tempout = L"";
  bool inEscape = false;
  for (auto wch: temp) {
    if (!inEscape) {
      if (wch==L'\\') {
        inEscape = true;
        continue;
      } else {
        tempout+=wch;
      }
    } else {
      switch (wch)
      {
      case L'n':
        tempout += L'\n';
        break;
      case L't':
        tempout +=L'\t';
        break;
      default:
        tempout +=wch;
        break;
      }
      inEscape = false;
    }
  }

  return wchar_to_uft8(tempout);

}

}
