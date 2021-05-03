#include "WindowsSubsys.h"
#include <windows.h>
namespace tmshell {

std::string GetLastErrorAsString() {
    //Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if(errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }
    
    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
    
    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);
    
    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);
            
    return message;
}

std::wstring utf8_to_wchar(std::string const & in) {
  std::wstring out;
  if (in.size() == 0) {
    return out;
  }

  int len = MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, in.c_str(), -1, NULL, 0);
#ifdef TMSHELLD_OUTPUT_TO_CONSOLE
  LOG_IF_FALSE(len > 0, "convert_fail:" + GetLastErrorAsString());
#endif
  out.resize(len - 1);
  MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, in.c_str(), -1, &out[0], len);

  return out;
}

std::string wchar_to_uft8(std::wstring const &in){
  std::string out;
  if (in.size() == 0) {
    return out;
  }

  int len = WideCharToMultiByte(CP_UTF8, 0, in.c_str(), -1, NULL, 0, NULL, NULL);
#ifdef TMSHELLD_OUTPUT_TO_CONSOLE
  LOG_IF_FALSE(len > 0, "convert_fail:" + GetLastErrorAsString());
#endif
  out.resize(len - 1);
  WideCharToMultiByte(CP_UTF8, 0, in.c_str(), -1, &out[0], len, NULL, NULL);
  return out;
}

WindowsSubsys::~WindowsSubsys() {
}

void WindowsSubsys::alert(std::string const & in) {
  std::thread th(
    [=](){
      std::wstring caption = TEXT("TMShell Alert");
      std::wstring content = utf8_to_wchar(in);
      int suc = MessageBox(NULL, content.c_str(), caption.c_str(), MB_ICONINFORMATION | MB_SYSTEMMODAL);
      ASSERT(suc>0, "msg:" + GetLastErrorAsString());
    }
  );
  th.detach();
  return;
}

bool WindowsSubsys::shell_open(std::string const & file, std::string & error_msg) {
  std::ifstream inputfile;
  try {
    inputfile.open(utf8_to_wchar(file));
  } catch (std::exception const & e) {
    error_msg = std::string(e.what()) + ":" + file;
    return false;
  }

  std::thread th(
    [=] () {
      std::wstring w_file = utf8_to_wchar(file);
      CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
      SHELLEXECUTEINFO seinfo;
      seinfo.cbSize = sizeof(seinfo);
      seinfo.fMask = SEE_MASK_NOASYNC | SEE_MASK_UNICODE | SEE_MASK_FLAG_LOG_USAGE;
      seinfo.hwnd = NULL;
      seinfo.lpVerb = NULL;
      seinfo.lpFile = w_file.c_str();
      seinfo.lpParameters = NULL;
      seinfo.lpDirectory = NULL;
      seinfo.nShow = SW_SHOWNORMAL;
      bool success = ShellExecuteEx(&seinfo);
      
      #ifdef TMSHELLD_OUTPUT_TO_CONSOLE
        LOG_IF_FALSE(success, "shell_open:" + GetLastErrorAsString());  
      #endif
    }
  );
  th.detach();

  return true;
}

std::string WindowsSubsys::file_read(const std::string & path) {
  std::ifstream inputFile;
  inputFile.open(utf8_to_wchar(path));
  std::stringstream ss;
  ss << inputFile.rdbuf();
  return ss.str();
}



} // namespace tmshell