// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];
	
	// TODO: Fill out the server ip and port
	std::string server_ip = "127.0.0.1";
	std::string server_port = "777";

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()

    cliend_fd = socket(AF_UNIX, SOCK_STREAM, 0);  

	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}

	// Check if the client socket was set up properly
	if(client_fd == -1){
		printf("Error- Socket setup failed");
		return -1;
	}
	
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)

    if (connect(client_fd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        
        error("ERROR connecting");

    }

	// TODO: Retreive user input

    int n;

    std::cin >> socket_read_buffer; // maybe?

	// TODO: Send() the user input to the server

    n = send(client_fd,socket_read_buffer,strlen(socket_read_buffer), MSG_NOSIGNAL);
    
    if (n < 0) {

        error("ERROR sending to socket");
    }
	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!
	
    n = read(client_fd,socket_read_buffer,1023);
    socket_read_buffer[1023] = '\0';
   
    if (n < 0) {

        error("ERROR reading from socket");

    }
    
    // TODO: Close() the socket
    
    close(sockfd);
	return 0; 
} 