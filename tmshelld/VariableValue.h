#pragma once
#include<string>
#include<chrono>
#include<memory>
#include<type_traits>
#include<unordered_map>

namespace tmshell {

using namespace std::chrono;

using Clock = std::chrono::system_clock;
using TimePoint = Clock::time_point;
using Duration = Clock::duration;

template<typename Rep>
struct get_type_id{};

#define REGISTER_TYPE_ID__L(A,B) template <> \
struct get_type_id<A> { \
  static constexpr int value = B; \
};

REGISTER_TYPE_ID__L(int, 0)
REGISTER_TYPE_ID__L(std::string, 1)
REGISTER_TYPE_ID__L(TimePoint, 2)
REGISTER_TYPE_ID__L(Duration, 3)

#undef REGISTER_TYPE_ID__L

template<typename Rep> 
constexpr int get_type_id_v = get_type_id<Rep>::value;



class StructValue;

class IVariableValue {
public:
  
  const static char* BaseVar[];

  template<typename Rep>
  static std::string getBaseVarName() {
    return BaseVar[get_type_id_v<Rep>];
  }

  template<typename To, typename Targ>
  static bool is(Targ* that) {
    To * new_that = dynamic_cast<To*>(that);
    return new_that != nullptr;
  }

  template<typename To, typename Targ>
  static bool is(const Targ* that) {
    const To * new_that = dynamic_cast<const To*>(that);
    return new_that != nullptr;
  }

  explicit IVariableValue(const std::string& type);
  virtual ~IVariableValue() = default;
  IVariableValue(const IVariableValue& that)= default;
  IVariableValue(IVariableValue&& that)= default;
  IVariableValue& operator=(const IVariableValue& that)= default;
  IVariableValue& operator=(IVariableValue&& that)= default;

  virtual std::string getTypeName() const final { 
    return _typeName; 
  }

  virtual bool isStruct() const final {
    return is<StructValue>(this);
  }

  virtual std::unique_ptr<IVariableValue> copy() const = 0;

private:
  std::string _typeName;
};



class StructValue: public IVariableValue {
public:
  explicit StructValue(const std::string&);
  virtual ~StructValue();
  StructValue(const StructValue& that);
  StructValue(StructValue&& that);
  StructValue& operator=(const StructValue& that);
  StructValue& operator=(StructValue&& that);

  static StructValue& ofPriodic(TimePoint start, TimePoint end, Duration repeat);

  IVariableValue* getField(const std::string& fieldName) const;
  bool checkField(const std::string& fieldName) const;
  bool addField(const std::string& fieldName, const IVariableValue* value);
  bool setField(const std::string& fieldName, const IVariableValue* value);
 
  virtual std::unique_ptr<IVariableValue> copy() const override {
    return std::make_unique<StructValue>(*this);
  }

private:
  std::unordered_map<std::string, std::unique_ptr<IVariableValue>> _field;
};



template<typename Rep, typename = typename std::enable_if_t<
  std::is_copy_assignable<Rep>::value
  && std::is_copy_constructible<Rep>::value>>
class SimpleVariableValue : public IVariableValue {
public:

  SimpleVariableValue(const Rep& r): IVariableValue(getBaseVarName<Rep>()) {
    _data = r;
  }
  virtual ~SimpleVariableValue() = default;
  SimpleVariableValue(const SimpleVariableValue& that)= default;
  SimpleVariableValue(SimpleVariableValue&& that) = default;
  SimpleVariableValue& operator=(const SimpleVariableValue& that) = default;
  SimpleVariableValue& operator=(SimpleVariableValue&& that) = default;

  Rep& get() { return _data; }
  void set(const Rep& r) { _data = r; }

  virtual std::unique_ptr<IVariableValue> copy() const override {
    return std::make_unique<SimpleVariableValue<Rep>>(*this);
  }

 private:
  Rep _data;
};


using IntValue = SimpleVariableValue<int>;
using StringValue = SimpleVariableValue<std::string>;
using TimePointValue = SimpleVariableValue<TimePoint>;
using DurationValue = SimpleVariableValue<Duration>;

std::string to_string(TimePoint tp);
TimePoint to_TimePoint(std::string in);

std::string to_string(Duration dur);
Duration to_duration(std::string in);

std::string to_string(StructValue sv);


}  // namespace tmshell