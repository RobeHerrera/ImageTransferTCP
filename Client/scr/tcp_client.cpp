//=============================================================================================
// CLASS       : client                                                                    =
// Description : TCP Client module that creates and manages an instance of a tcp client       =
//=============================================================================================

#include "../inc/tcp_client.h"

#include <cstring>
#include <iostream>

using namespace std;

int IsBigEndian()
{
    int i = 1;
    char *p = (char *)&i;

    if (p[0] == 1)
        return 0; //Little
    else
        return 1; //Big
}


uint16_t ChangeEndianness(uint16_t value)
{
    uint16_t result = 0;
    result |= (value & 0x00FF) << 8;
    result |= (value & 0xFF00) >> 8;
    return result;
}



namespace tcp
{
// ---------------------------------------------------------------------------------------------
// Summary        : Create new instance of tcp client class (Class constructor)
//
// Pre-Condition  : None
// Post-Condition : None
//
// Input :-
//        > [string] host_address_name : address name of the host i.e ["192.186.0.4"]
//        > [int]    port_number       : port of host node i.e [8080]
//
// Output:-
//        > None
// ---------------------------------------------------------------------------------------------
client :: client (string host_address_name, int port_number) : Node(port_number)
{

    // initialize host address struct
    host_address.sin_family      = __type_internet_domain_sockets__;
    host_address.sin_addr.s_addr = inet_addr( host_address_name.c_str() );

    if(IsBigEndian())
    {
        //Big Endian
        host_address.sin_port    = port_number;
    }
    else
    {
        //Little Endian
        host_address.sin_port    = htons(port_number);
        //host_address.sin_port = ChangeEndianness(port_number);
    }


    // initialize connection socket
    socket_fd = socket( __type_internet_domain_sockets__, __type_byte_stream_socket__, 0 );

    if (socket_fd == -1)
    {
        printf("\nCould not create socket...");
    }

}

// ---------------------------------------------------------------------------------------------
// Summary : Connect to host node
// ---------------------------------------------------------------------------------------------
int client :: Connect ()
{
    //Connect to remote node
    if (connect( socket_fd, (struct sockaddr *)&host_address, sizeof(host_address)) < 0)
    {
        cout<<strerror(errno)<<endl;
        close(socket_fd);
        puts("Connect Error");
        return 1;
    }
    else
    {
        char str[INET_ADDRSTRLEN];
        cout << "Connected to: " << inet_ntop(AF_INET, &(host_address.sin_addr), str, INET_ADDRSTRLEN) <<" port: " << ntohs(host_address.sin_port) << std::endl;
    }
    return 0;

}

/***************************************************************************************************
 Summary: Stop communication
 Parameters: Socked_fd, number of the port to listen the conection
*************************************************************************************************/

void client :: Stop ()
{
    close(socket_fd);

}

// ---------------------------------------------------------------------------------------------
// Summary      : Send message to currently connected host
// Pre-Condition: client must has an open connection with host
// ---------------------------------------------------------------------------------------------
void client :: Send(string message)
{
    try
    {

        // send the message to host's open socket
        sendto( socket_fd, message.c_str(), strlen(message.c_str()), 0, (struct sockaddr *)&host_address,sizeof(host_address));

        cout << "Message Sent: "<< message << std::endl;

    }
    catch(int exp)
    {
        printf("Error in send image");

    }
}


/***************************************************************************************************
 Summary: sen
 Parameters: Socked_fd, number of the port to listen the conection
*************************************************************************************************/

int client :: ReceivedText()
{


    // recieve incoming message from host
    incoming_message_length = recvfrom(socket_fd,incoming_message,_MSG_BUFFER_SIZE_,0,NULL,NULL);

    // check if message is not empty
    if(incoming_message_length > 0)
    {

        //put trailing character
        incoming_message[incoming_message_length] = 0;

        //print the message [for testing purposes]
        cout << "message: " << incoming_message << std::endl;
    }


    // close host connection socket
    close(socket_fd);

    return 1;

}


/***************************************************************************************************
 Summary: received image from the server
 Parameters: Socked_fd, number of the port to listen the conection
*************************************************************************************************/

int client :: ReceivedImage(char nameImage[])
{
    // Start function

    int recv_size = 0,size = 0, read_size, write_size, packet_index =1,stat;

    char imagearray[10241];
    FILE *image;

//Find the size of the image
    do
    {
        stat = read(socket_fd, &size, sizeof(int));
    }
    while(stat<0);

    printf("Packet received.\n");
    printf("Packet size: %i\n",stat);
    printf("Image size: %i\n",size);
    printf(" \n");

    char buffer[] = "Got it";

//Send our verification signal
    do
    {
        stat = write(socket_fd, &buffer, sizeof(int));
    }
    while(stat<0);

    printf("Reply sent\n");
    printf(" \n");

    image = fopen(nameImage, "w");

    if( image == NULL)
    {
        printf("Error has occurred. Image file could not be opened\n");
        return -1;
    }

//Loop while we have not received the entire file yet
    struct timeval timeout = {10,0};

    fd_set fds;
    int buffer_fd;

    while(recv_size < size)
    {

        FD_ZERO(&fds);
        FD_SET(socket_fd,&fds);

        buffer_fd = select(FD_SETSIZE,&fds,NULL,NULL,&timeout);

        if (buffer_fd < 0)
            printf("error: bad file descriptor set.\n");

        if (buffer_fd == 0)
            printf("error: buffer read timeout expired.\n");

        if (buffer_fd > 0)
        {
            do
            {
                read_size = read(socket_fd,imagearray, 10241);
            }
            while(read_size <0);

            printf("Packet number received: %i\n",packet_index);
            printf("Packet size: %i\n",read_size);


            //Write the currently read data into our image file
            write_size = fwrite(imagearray,1,read_size, image);
            printf("Written image size: %i\n",write_size);

            if(read_size !=write_size)
            {
                printf("error in read write\n");
            }


            //Increment the total number of bytes read
            recv_size += read_size;
            packet_index++;
            printf("Total received image size: %i\n",recv_size);
            printf(" \n");
            printf(" \n");
        }

    }


    fclose(image);
    printf("Image successfully Received!\n");

    /***********  Inject Metadata ***************/
    printf("Now inject Metadata to the image!\n");


    /*******************************************/
    return 1;
}

}//End namespace
