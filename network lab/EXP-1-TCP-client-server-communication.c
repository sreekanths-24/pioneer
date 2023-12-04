Server side

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX_BUFFER_SIZE 1024
#define PORT 12345
int main() {
    int server_socket, client_socket, read_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    char response[MAX_BUFFER_SIZE] = "Hello, client!";
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))
    listen(server_socket, 5);
    printf("Server listening on port %d\n", PORT);
    int addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addr_len);
    printf("Client connected\n");
    read_size = recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Received data from client: %s\n", buffer);
    write(client_socket, response, strlen(response));
    close(client_socket);
    close(server_socket);
    return 0;
}
--------------------------------------------------------------------------------------
Client Side:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define PORT 12345
int main() {
    int client_socket, read_size;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE] = "Hello, server!";
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);
  connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
 send(client_socket, message, strlen(message), 0);
    read_size = recv(client_socket, buffer, sizeof(buffer), 0);
printf("Received data from server: %s\n", buffer);
    close(client_socket);
    return 0;
}

--------------------------------------------------------------------
To compile and run using this command on shell prompt
gcc -o server server.c
./server
gcc -o client client.c
./client
