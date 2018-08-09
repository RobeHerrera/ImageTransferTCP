#include <iostream>
#include "../inc/tcp_server.h"
#include <sstream>

using std::string;
using std::cout;
using std::cin;

void print(Node *nd, string msg)
{
    cout<< nd->ip <<" : " << msg << std::endl;
}

int main(int argc, char** argv)
{

    //initialize default port number and max connection cout
    int port = 12002;

    // check if there are any passed arguments
    if(argc > 1)
    {
        // initialize string stream from argument
        std::istringstream arg_stream(argv[1]);

        // bind arguments stream to port int variable if valid
        if ( !(arg_stream >> port) )
        {
            std::cerr << "Invalid number " << argv[1] << '\n';
        }
        else
        {
            printf("Port: %d",port);
        }
    }

    // create server instance with specified port number
    tcp::server server(port);
    // set async fn to handle incoming messages
    server.OnMessage(print);

    /*********************************
    Create menu to choose what to do
    **********************************/

    //enum actions {RUN_SERVER, STOP_SERVER, RECEIVED_TEXT, RECEIVED_IMG, SEND_TEXT, SEND_IMG, EXIT};
    enum actions {RUN_SERVER, STOP_SERVER, RECEIVED_TEXT,SEND_IMG, EXIT};
    int opt;
    do
    {
        cout << "\n\nSERVER - What do you want to do?" << std::endl;
        //cout << "0 - Run Server\n1 - Stop Server\n2 - Received Text\n3 - Received Img\n4 - Send Text\n5 - Send Img\n6 - EXIT\n";
        cout << "0 - Run Server\n1 - Stop Server\n2 - Received Text\n5 - Send Img\n6 - EXIT\n";
        cin >> opt;

// Error using switch (something about jump)
        switch(opt)
        {
        case RUN_SERVER:
        {
            int result = server.Run();
            if(result != 0)
            {
                cout << "Failed to start server !" << std::endl;
            }
        }break;

        case STOP_SERVER:
        {
            int result = server.Stop();
            if(result != 0)
            {
                cout << "Failed to stop server !" << std::endl;
            }
        }break;

        case RECEIVED_TEXT:
        {
            //start listening to connections
            int result = server.Listen(); //this line causes the error using switch case
            if(result == 1)
            {
                cout << "Complete..." << std::endl;
            }
        }
            break;


        case SEND_IMG:
            server.SendImage();
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

