//=============================================================================================
// CLASS       : client                                                                    =
// Description : TCP Client module that creates and manages an instance of a tcp client       =
//=============================================================================================

#ifndef _TCP_CLIENT_HPP_
#define _TCP_CLIENT_HPP_

#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <netinet/in.h> // Needed for internet addresses
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<fstream>
#include<errno.h>

// library specific headers
#include "node.h"
#include "utils.h"

using namespace std;

namespace tcp{
  class client : public Node
  {

  public:

    // initialize a new tcp client instance
    client(string, int);

    // connect to host node
    int Connect(void);

    // send message to currently connected host node
    void Send(string);

    // send typed message to currently connected host node
    void Send(string,string);

    // send message to specific connected socket address
    void Send(struct sockaddr*, string);

    // send typed message to specific connected socket address
    void Send(struct sockaddr*,string,string);

    // Stop connection with host
    void Stop();

    // Received an image
    int ReceivedImage();

    // Received Text
    int ReceivedText();

  private:

    // child proceess id
    pid_t  _childpid;

  };
}
#endif

