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

namespace tcp
{
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
    int ReceivedImage(char nameImage[]);

    // Received Text
    int ReceivedText();

    struct hostent *hostPtr;    // Entry within the host address database




    char* getHostIPAddress()
    {
        struct in_addr *addr_ptr;
        // the first address in the list of host addresses
        addr_ptr = (struct in_addr *)*hostPtr->h_addr_list;
        // changed the address format to the Internet address in standard dot notation
        return inet_ntoa(*addr_ptr);
    }

    // Retrieves the hosts name
    char* getHostName()
    {
        return hostPtr->h_name;
    }

   string getMyIPAddress();

private:

    // child proceess id
    pid_t  _childpid;

    int is_local(const struct sockaddr *addr, socklen_t addr_len);


};
}
#endif

