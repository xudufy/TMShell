#pragma once
#include "../common/common.h"

namespace tmshell {

std::wstring utf8_to_wchar(std::string const &);

std::string wchar_to_uft8(std::wstring const &);

//All thread created here are detached for releasing resources. 
//Make sure the main() will run forever, otherwise the gui will close when main() exits.
class WindowsSubsys{
public:
  static WindowsSubsys& getInstance() {
    static WindowsSubsys instance; 
    return instance;
  }

private:
  WindowsSubsys() {}
  ~WindowsSubsys();
public:
  WindowsSubsys(WindowsSubsys const&) = delete;
  void operator=(WindowsSubsys const&) = delete;

  void alert(std::string const & in);

  bool shell_open(std::string const & file, std::string & out_error_msg);

  std::string file_read(const std::string & path);
  
private:
  std::mutex objmtx;

};

} // namespace tmshell