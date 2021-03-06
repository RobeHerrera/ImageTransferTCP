#include <iostream>
#include "../inc/tcp_client.h"
#include <sstream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::string;

void getMyIPAddress()
{
    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next)
    {
        if (!ifa->ifa_addr)
        {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET)   // check it is IP4
        {
            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printf("%s IPv4 Address %s\n", ifa->ifa_name, addressBuffer);
        }
//        else if (ifa->ifa_addr->sa_family == AF_INET6)     // check it is IP6
//        {
//            // is a valid IP6 Address
//            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
//            char addressBuffer[INET6_ADDRSTRLEN];
//            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
//            printf("%s IPv6 Address %s\n", ifa->ifa_name, addressBuffer);
//        }
    }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
}




int main(int argc, char** argv)
{
    // initialize default port number and max connection cout
    int     port    = 12002;
    //string  address = "192.168.99.100";
    string  addressHost = "127.0.0.1";

    // check if there are any passed arguments
    if(argc == 3)
    {
        //.Client <Port> <hostAddress>
        addressHost = argv[2];
        string strPort = argv[1];

        // initialize string stream from argument
        std::istringstream arg_stream(strPort);

        // bind arguments stream to port int variable if valid
        if ( !(arg_stream >> port) )
            std::cerr << "Invalid number " << strPort << '\n';

    }
    //Ask for the necesary info
    else
    {
        cout << "Enter Port: ";
        cin >> port;

        cout << "Enter Host Addres: ";
        cin >> addressHost;


    }



    // create server instance with specified port number
    tcp::client client(addressHost,port);

    //printf("cambio de endian de 12002: %x -> %x ",12002, ChangeEndianness(12002));
    getMyIPAddress();



    /*********************************
    Create menu to choose what to do
    **********************************/

    // enum actions {CONNECT_TO_SERVER, STOP_CLIENT, RECEIVED_TEXT, RECEIVED_IMG, SEND_TEXT, SEND_IMG, EXIT};
    enum actions {CONNECT_TO_SERVER, RECEIVED_IMG, SEND_TEXT, EXIT};
    int opt;
    do
    {
        cout << "\n\nSERVER - What do you want to do?" << std::endl;
        cout << "0 - Connect to Server\n1 - Received Img\n2 - Send Text\n3 - EXIT\n";
        cin >> opt;

// Error using switch (something about jump)
        switch(opt)
        {
        case CONNECT_TO_SERVER:
        {
            // connect to host node
            client.Connect();
        }
        break;

        case RECEIVED_IMG:
        {
            char nameImage[] = "image.jpeg";
            client.ReceivedImage(nameImage);

            char szBuffer[1024];
            struct hostent *host = gethostbyname(szBuffer);



//            ((struct in_addr *)(host->h_addr))->S_un.S_un_b.s_b1;
//
//            openHostDb();
//            string localHostName = client.getHostName();
//            string localHostAddr = client.getHostIPAddress();

//            cout << "----------------------------------------" << endl;
//            cout << "   My local host information:" << endl;
//            cout << "         Name:    " << localHostName << endl;
//            cout << "         Address: " << localHostAddr << endl;
//            cout << "----------------------------------------" << endl;

            // Check  metadata with exiftool
            //string cmd = "exiftool -UserComment ";
            printf("Print metadata with exiftool!\n");
            string cmd = "exiftool -UserComment ";
            cmd  = cmd + nameImage;
            const char *command = cmd.c_str();
            system(command);
        }
        break;

        case SEND_TEXT:
        {
            // send message to host
            client.Send("Hi! - from client desde la casa de Robe");


        }
        break;

        case EXIT:
            // Do nothing
            cout << "Bye." << std::endl;
            break;
        }

    }
    while(opt != EXIT);



    return 0;
}

