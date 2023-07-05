
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define CONNECTION_PORT 3500

int main(int argc, char** argv)
{
	//handle command line args
	

	// server socket 
    int socket_descriptor;
    int client_socket;

	// buffer to store message
    char storage_buffer[80];
    int length_of_address;
    int option_value=1;

	// server and client address structures
    struct sockaddr_in server_address;
    struct sockaddr_in connection_address;

    char* message = "This is a message from the server";

	puts("Server starting...");

    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }    

	// set server socket options
    int status=setsockopt(socket_descriptor, SOL_SOCKET,SO_REUSEADDR , &option_value,sizeof(option_value));
    if (status < 0) {
    	perror("Couldn't set options");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(CONNECTION_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_zero[8] = '\0';

	// bind server socket
    status = bind(socket_descriptor, (struct sockaddr*)&server_address, sizeof(struct sockaddr));
    if (status < 0) {
        perror("Couldn't bind socket");
        exit(EXIT_FAILURE);
    }

	// listen for client connection
    status = listen(socket_descriptor,4);
    if (status < 0) {
        perror("Couldn't listen for connections");
        exit(EXIT_FAILURE);
    }

    length_of_address = sizeof(connection_address);
    client_socket = accept(socket_descriptor, (struct sockaddr*)&connection_address, &length_of_address);
    if (client_socket < 0) {
        perror("Couldn't establish connection with client");
        exit(EXIT_FAILURE);
    }

	// get client response and send message
    ssize_t bytes_read = read(client_socket, storage_buffer, 80);
    storage_buffer[bytes_read - 1] = '\0';
    printf("Message from client: %s \n",storage_buffer);
    send(client_socket, message, strlen(message), 0);

    close(socket_descriptor);
    close(client_socket);

    return 0;
}
