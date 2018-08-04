#include <iostream>
#include "../inc/tcp_client.h"
#include <sstream>
#include <string>

using std::string;

int main(int argc, char** argv)
{

    // initialize default port number and max connection cout
    int     port    = 12002;
    string  address = "127.0.0.1";

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



    /*********************************
    Create menu to choose what to do
    **********************************/

    enum actions {CONNECT_TO_SERVER, STOP_CLIENT, RECEIVED_TEXT, RECEIVED_IMG, SEND_TEXT, SEND_IMG, EXIT};
    int opt;
    do
    {
        cout << "\n\nSERVER - What do you want to do?" << std::endl;
        cout << "0 - Connect to Server\n1 - Stop Client\n2 - Received Text\n3 - Received Img\n4 - Send Text\n5 - Send Img\n6 - EXIT\n";
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

        case STOP_CLIENT:
        {
            client.Stop();

        }
        break;

        case RECEIVED_TEXT:
        {


        }
        break;

        case RECEIVED_IMG:
        {
            char nameImage[] = "image.jpeg";
            client.ReceivedImage(nameImage);

            // Check  metadata with exiftool
            //string cmd = "exiftool -UserComment ";
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

        case SEND_IMG:

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

