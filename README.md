# ImageTransferTCP
## Transfer Images through TCP protocol using Docker Containers

#### Inital version V1.0

If you want to see the complete steps to complete the activity 
please see the DOC included in this repo.

### Updates 19 / JUL / 2018
- Install Linux with Dockek.
- Learning how to use Docker.
- Initial version of the files: Client.cpp and Server.cpp.

### Updates 20 / JUL / 2018
- Learning what is docker.

### Updates 21 / JUL / 2018
- Learning how to create a docker image.

### Updates 22 / JUL / 2018
- Search for a simple example of TCP protocol.

### Update 23 /JUL / 2018
- Create Code::Blocks project for TCP example.
- Upload to GitHub.

### Update 24 / JUL / 2018
- Search for general information about Docker Machines.

### Update 25 / JUL / 2018
- Look for how to run programs in docker-machines.

### Update 26 / JUL / 2018
- Added VM for Server and test with my local.

### Update 27 / JUL / 2018
- Upload Program TCP images transfer.

### Update 28/ JUL / 2018
- Integrate program to server transfer images using classes.

### Update 29/ JUL / 2018
- Day off.

### Update 30/ JUL / 2018
- No update.

### Update 31/ JUL / 2018
- Create Menu for Client and integrate image received.

### Update 1 / AUG / 2018
- No update.

### Update 2 / AUG / 2018
- No update.

### Update 3 / AUG / 2018
- Execute Command extern from Client side to use exiftool to read UserComment in the image received.

### Update 4 / AUG / 2018
- Add system() to add metadata in the image.

### Update 5 / AUG / 2018
- Manage the header IP TCP to set the correct UserComment.

### Update 6 / AUG / 2018
- TODO: Complete image of Docker one for Server and other for Client.

## PENDING TASKS:
- Accept more than one connection.
- Create a docket images to recreate all this.
- How I can I get the complte IP header, in wich buffer or struct is stored.

## REQUIREMENTS
1.- Use docker containers to emulate two machines connected in same network, all the solution needs to be able to download and run.
-> Using Docker machine to emulate to machines with differents ips address

2.- Machine platform: Linux OS
-> I used Codeblocks and Ubuntu 18.04.1 LTS

3.- Language: C++
-> C/C++

4.- Upload progress in your github account and report your first commit with the engineer that sent you this challenge (just for tracking purposes).
-> Ypu can see my progress in the next repository in gitHub:
 https://github.com/RobeHerrera/ImageTransferTCP.git

5.- The solution shall use IPv4 Internet protocols TCP/IP to communicate.
-> Using IPv4 but we can use IPv6 changin some macros in the Sockets functions. (ex: sockaddr_in6 intead of sockaddr_in)

6.- The machine that is receiving the image shall evaluate if the transfer came from same network or local network (ipv4 header). Try to use bitwise operators (shifts, logical ops. etc) to resolve this point (network endianness).
-> this is made by the operations:  htons() and ntohs() to change the byte order, so we need only to identify in wich machine we are working on.
**

7.- Solution shall being programmed to run in both of big endian and little endian (portable code, at least in Linux)
-> This only is in the bit wise operators and only to procted this operation with the functions: IsBigEndian() and ChangeEndianness()

8.- When an image is received, inject exif data into User Comment field, with following info:
• source_ip:<the.source.ip.address> , is_from_local_network:<true | false>
-> in the Client side make this injection of the code with exiftool command.

9.- The image received shall being checked with an exif reader command.
-> I used the command exiftool to write and read the metadata of the image.

10.- Please document (Readme.txt) the how to run your solution.
-> This README file and googleDoc online.
https://docs.google.com/document/d/1n2DJziuf2PPqxj4YZTYF2YOhK-QtAjWF4kPC7xDYB-k/edit?usp=sharing 

Functionality:
1.- We need to Run the Server (Server opt = 0).
2.- Connect with the Client (Client opt = 0).
3.- The Server send a image to the Client (Server opt = 5).
4.- The Client must accept this connection (Client opt = 3).
5.- Confirm in the console that the verification of exiftool has been done.


