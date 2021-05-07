#include "../common/common.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <cstdlib>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>

#include <boost/filesystem.hpp>
using namespace boost::filesystem;

#include "../parser/TMSlang.h"

using namespace tmshell;
using namespace antlr4;

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class WSClient {
public:
  WSClient():ioc(), ws(ioc) {
    ws.binary(true);
  }

  ~WSClient() {
    try {
      ws.close("Client exits.");
    } catch (std::exception const & e) {
      std::cerr<<e.what()<<std::endl;
    }
  }

  void init(){
    try {
      tcp::resolver resolver(ioc);
      auto result = resolver.resolve(TMSHELL_SERVICE_HOST, std::to_string(TMSHELL_SERVICE_PORT));
      std::cout << result.begin()->endpoint().address();
      net::connect(ws.next_layer(), result.begin(), result.end());
      ws.handshake(TMSHELL_SERVICE_HOST, TMSHELL_SERVICE_PATH);
    } catch (std::exception const & e) {
      std::cerr << "Error: " << e.what() << std::endl;
      throw;
    }

  }
  void send(const std::string & msg) {
    try {
      ws.write(net::buffer(std::string(msg)));
      beast::multi_buffer buffer;
      ws.read(buffer);
      std::cout<<beast::buffers_to_string(buffer.data());
    } catch (std::exception const & e) {
      std::cerr << "Error: " << e.what() << std::endl;
      throw;
    }

  }

  net::io_context ioc;
  websocket::stream<tcp::socket> ws;
};

class InteractiveMode {
public:
  int main() {
    wsClient.init();
    std::string partialCommand;
    while(true) {
      
      std::string line;
      std::getline(std::cin, line);
      line += "\n";

      partialCommand += line;
      
      ParserInstance parser(partialCommand);
      parser.parseLine();
      
      if (parser.isComleted()) {
        wsClient.send(partialCommand);
        partialCommand.clear();
      } else if (parser.getOffending() == "<EOF>") {
        std::cout << ">>> ";
        continue;
      } else {
        std::cout << parser.getLastError() << std::endl; 
        partialCommand.clear();
      }
    }
  }

private:
  WSClient wsClient;
};

int main(int argc, char* argv[]) {
  if (argc == 1) { //interactive mode
    InteractiveMode _main;
    _main.main();
  } else { //file mode
    WSClient wsClient;
    wsClient.init();
    std::string content;
    content.reserve(4096);
    for (int i = 1; i < argc; i++) {
      std::ifstream inputFile;
      try {
        inputFile.open(argv[i]); 
      } catch (std::exception const & e) {
        std::cerr<<e.what()<<std::endl;
        exit(-1);
      }
      std::stringstream ss;
      ss << inputFile.rdbuf();
      content += ss.str();
      content += "\n";
    }
    wsClient.send(content);
  }
  return 0;
}