//==============================================================================================
//= CLASS       : server                                                                       =
//= Description : TCP Server module that creates and manages an instance of a tcp server       =
//==============================================================================================

#include "../inc/tcp_server.h"
#include <stdexcept>
#include <iostream>

using namespace std;

int IsBigEndian() {
    int i = 1;
    char *p = (char *)&i;

    if (p[0] == 1)
        return 0;
    else
        return 1;
}

namespace tcp
{

// ---------------------------------------------------------------------------------------------
// Create new tcp server instance
// ---------------------------------------------------------------------------------------------
server :: server (int portNumber)
{
    //initialize port number and stop server flag
    _port             = portNumber;
    _stop_server_flag = 0;

    // initialize the server address struct with zero byte stream
    bzero(&_server_address, sizeof(_server_address));

    _server_address.sin_family      = AF_INET;           // IP version not specified. Can be both.
    _server_address.sin_addr.s_addr = htonl(INADDR_ANY); // make server accept all addresses

        if(IsBigEndian()){
    //Big Endian
    _server_address.sin_port        = _port;      // Set port number in type [network byte order]
        }else{
    //Little Endian
    _server_address.sin_port        = htons(_port);      // Set port number in type [network byte order]
    // _server_address.sin_port  = ChangeEndianness(port_number);
    }


    // initialize socket with [internet addresses, socket stream sequences with default protocol]
    _server_socket_fd = socket( __type_internet_domain_sockets__, __type_byte_stream_socket__, 0);

}

int server :: Run ()
{
    int accepted_num_of_connections = 100000;

    // bind the address name and port number to the scoket address struct
    int bind_result   = bind(_server_socket_fd,(struct sockaddr *)&_server_address,sizeof(_server_address));

    int listen_result = listen(_server_socket_fd, accepted_num_of_connections);

    // start listening to the port
    if ( listen_result != 0 || bind_result != 0)
    {
        return -1;
    }
    else
    {
        cout << "Start listening at port " << _port << std::endl; // For testing purposes
    }

    return listen_result;

}
// ---------------------------------------------------------------------------------------------
// start listening at specified port with limited number of connections at the same time
// ---------------------------------------------------------------------------------------------
int server :: Listen ()
{
    // initialize client address struct and accept new connection
    _client_address_length = sizeof( _client_address_length);

    _client_socket_fd = accept( _server_socket_fd, (struct sockaddr *)&_client_address, &_client_address_length);


    /*Do I really need this condition*/
    // skip iteration if no incoming connections
    if(_client_socket_fd == -1)
        return 0;

    cout << "Connection accepted - " << _client_socket_fd << std::endl;

    // recieve a message from client to msg buffer
    _message_length = recvfrom( _client_socket_fd, _message, _MSG_BUFFER_SIZE_, 0, (struct sockaddr *)&_client_address,&_client_address_length);

    // check if there is no more messages
    if(_message_length <= 0)
    {
        close(_client_socket_fd);
        cout << "Connection lost - " << _client_socket_fd << std::endl;
        //break;
    }

    // put trailing characters
    _message[_message_length] = 0;
    string msg_str(_message);

    // execute OnMessage function if available
    if ( _on_msg_fn_ptr  != NULL)
    {
        try
        {
            std::string client_ip = inet_ntoa(_client_address.sin_addr);

            Node* nd = new Node("",client_ip,"");
            this -> _on_msg_fn_ptr(nd,msg_str);
        }
        catch(std::exception exp)
        {
            std::cerr << "failed to execute [OnMessage] function";
        }
    }
    //close(_client_socket_fd);
    return 1;
}

// ---------------------------------------------------------------------------------------------
// Summary: Stop server from listening
// ---------------------------------------------------------------------------------------------

int server :: Stop()
{
    _stop_server_flag = 1;

    int res = close(_client_socket_fd);

    //This function I found it in the documentation of socket.h
    shutdown (_server_socket_fd, SHUT_RDWR);

    return res;
}

// ---------------------------------------------------------------------------------------------
// Summary: Assign on message recieved behavoir
// ---------------------------------------------------------------------------------------------
void server :: OnMessage(void (*fptr)(Node*, std::string))
{
    _on_msg_fn_ptr = fptr;
}



/***********************************************************************
 Funciton: send_image(int socket, *array imageFile)

 Summary: Senf image to specific socket
 Paramters:

    socket-> Port number of the socket int
    imageFile-> name of the file or path.

************************************************************************/
void server :: SendImage()
{

    //Accept and incoming connection
    puts("Waiting for incoming connections...");

    // initialize client address struct and accept new connection
    _client_address_length = sizeof( _client_address_length);

    _client_socket_fd = accept( _server_socket_fd, (struct sockaddr *)&_client_address, &_client_address_length);

    fflush(stdout);

    if (_client_socket_fd<0)
    {
        perror("Accept Failed");
        return;
    }

    int socket = _client_socket_fd;
    FILE *picture;
    int size, read_size, stat, packet_index;
    char send_buffer[10240], read_buffer[256];
    packet_index = 1;

    /*************************INJECT METADATA TO THE IMAGE **************************/
    // TODO: get the the correct information
    // Function Stub ¡
    char strSourceIP[INET_ADDRSTRLEN];
    const char *nameImage = "images/2.jpg";

    inet_ntop(AF_INET, &(_server_address.sin_addr), strSourceIP, INET_ADDRSTRLEN);

    string cmd = "exiftool -m -UserComment=\"source_ip:";
    cmd  = cmd + strSourceIP +"\" "+nameImage;
//    const char *command = cmd.c_str();

    /*This should be injected in the Client side*/
    //printf("%s\n",command);
    //system(command); // "exiftool -m -UserComment=source_ip:127.0.0.1"


//    system("exiftool -m -UserComment=\"Comentario desde asdf\" images/2.jpg");
    //Verify if the image get the correct value

    cmd = "exiftool -UserComment ";
    cmd  = cmd + nameImage;
    const char *command2 = cmd.c_str();
    printf("%s\n",command2);
    system(command2);
    //system("exiftool -UserComment images/2.jpg");


    /***************************************************************************/

    picture = fopen(nameImage, "r");
    printf("Getting Picture Size\n");

    if(picture == NULL || picture == 0)
    {
        printf("Error Opening Image File");
    }

    fseek(picture, 0, SEEK_END);
    size = ftell(picture);
    fseek(picture, 0, SEEK_SET);
    printf("Total Picture size: %i\n",size);

    //Send Picture Size
    printf("Sending Picture Size\n");
    write(socket, (void *)&size, sizeof(int));

    //Send Picture as Byte Array
    printf("Sending Picture as Byte Array\n");

    do   //Read while we get errors that are due to signals.
    {
        stat=read(socket, &read_buffer, 255);
        printf("Bytes read: %i\n",stat);
    }
    while (stat < 0);

    printf("Received data in socket\n");
    printf("Socket data: %s\n", read_buffer);

    while(!feof(picture))
    {
        //while(packet_index = 1){
        //Read from the file into our send buffer
        read_size = fread(send_buffer, 1, sizeof(send_buffer)-1, picture);

        //Send data through our socket
        do
        {
            stat = write(socket, send_buffer, read_size);
        }
        while (stat < 0);

        printf("Packet Number: %i\n",packet_index);
        printf("Packet Size Sent: %i\n",read_size);
        printf(" \n");
        printf(" \n");


        packet_index++;

        //Zero out our send buffer
        bzero(send_buffer, sizeof(send_buffer));
    }

    close(_client_socket_fd);
    fflush(stdout);
}// End sendImage

}// end of the spacename TCP
