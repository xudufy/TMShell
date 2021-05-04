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
REGISTER_TYPE_ID__L(bool, 1)
REGISTER_TYPE_ID__L(std::string, 2)
REGISTER_TYPE_ID__L(TimePoint, 3)
REGISTER_TYPE_ID__L(Duration, 4)

#undef REGISTER_TYPE_ID__L

template<typename Rep> 
constexpr int get_type_id_v = get_type_id<Rep>::value;


class StructValue;

inline std::string to_string(int i) {
  return std::to_string(i);
}

inline std::string to_string(bool i) {
  return i?"true":"false";
}

inline std::string to_string(const std::string & i) {
  return i;
}

std::string to_string(TimePoint const & tp);
TimePoint to_TimePoint(std::string const & in);

void find_next_occurance(tm ref, tm & dst); //exported for test purpose.

std::string to_string(Duration const & dur);
Duration to_Duration(std::string const & in);
std::string to_string(StructValue const & sv);

std::string unescape_string(std::string const & in);

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

  virtual std::string to_string() = 0;

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

  static StructValue ofPriodic(TimePoint start, TimePoint end, Duration repeat);

  IVariableValue* getField(const std::string& fieldName) const;
  bool checkField(const std::string& fieldName) const;
  bool addField(const std::string& fieldName, const IVariableValue & value);
  bool setField(const std::string& fieldName, const IVariableValue & value);
 
  virtual std::unique_ptr<IVariableValue> copy() const override {
    return std::make_unique<StructValue>(*this);
  }

  virtual std::string to_string() {
    return tmshell::to_string(*this);
  }

  friend std::string to_string(StructValue const &);

private:
  std::unordered_map<std::string, std::unique_ptr<IVariableValue>> _field;
};



template<typename Rep, typename = typename std::enable_if_t<
  std::is_copy_assignable<Rep>::value
  && std::is_copy_constructible<Rep>::value>>
class SimpleVariableValue : public IVariableValue {
public:
  using value_type = Rep;

  SimpleVariableValue(const Rep& r): IVariableValue(getBaseVarName<Rep>()) {
    _data = r;
  }
  virtual ~SimpleVariableValue() = default;
  SimpleVariableValue(const SimpleVariableValue& that)= default;
  SimpleVariableValue(SimpleVariableValue&& that) = default;
  SimpleVariableValue& operator=(const SimpleVariableValue& that) = default;
  SimpleVariableValue& operator=(SimpleVariableValue&& that) = default;

  Rep get() { return _data; }
  void set(const Rep& r) { _data = r; }

  virtual std::unique_ptr<IVariableValue> copy() const override {
    return std::make_unique<SimpleVariableValue<Rep>>(*this);
  }

  virtual std::string to_string() {
    return tmshell::to_string(_data);
  }

 private:
  Rep _data;
};


using IntValue = SimpleVariableValue<int>;
using BoolValue = SimpleVariableValue<bool>;
using StringValue = SimpleVariableValue<std::string>;
using TimePointValue = SimpleVariableValue<TimePoint>;
using DurationValue = SimpleVariableValue<Duration>;

class VoidValue: public IVariableValue {
public:
  VoidValue(): IVariableValue("void"){}
  virtual ~VoidValue() = default;
  VoidValue(const VoidValue& that)= default;
  VoidValue(VoidValue&& that) = default;
  VoidValue& operator=(const VoidValue& that) = default;
  VoidValue& operator=(VoidValue&& that) = default;

  virtual std::unique_ptr<IVariableValue> copy() const override {
    return std::make_unique<VoidValue>(*this);
  }

  virtual std::string to_string() {
    return "<void>";
  }
};

template<typename Rep>
Rep iv_get(IVariableValue & c) {
  return dynamic_cast<SimpleVariableValue<Rep> &>(c).get();
}

template<typename Rep>
Rep iv_get(IVariableValue * c) {
  return dynamic_cast<SimpleVariableValue<Rep> *>(c)->get();
}


}  // namespace tmshell