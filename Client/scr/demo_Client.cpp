

#include <iostream>
#include "../inc/tcp_client.h"
#include <sstream>
#include <string>

using std::string;

int main(int argc, char** argv)
{

  // initialize default port number and max connection cout
  int     port    = 12002;
  string  address = "192.168.99.100";

  // check if there are any passed arguments
  if(argc == 3)
  {
    // initialize string stream from argument
    std::istringstream arg_stream(argv[1]);

    // bind arguments stream to port int variable if valid
    if ( !(arg_stream >> port) )
      std::cerr << "Invalid number " << argv[1] << '\n';
  }

  // create server instance with specified port number
  tcp::client client(address,port);

  // connect to host node
  client.Connect();

  // send message to host
  client.Send("Hi! - from client desde la casa de Robe");



  return 0;
}

