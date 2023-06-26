client program-------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytesRead;    
int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUFFER_SIZE];    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);    
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);    
    inet_pton(AF_INET, SERVER_IP, &(serverAddr.sin_addr));      
    connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));     
    printf("Connected to server: %s:%d\n", SERVER_IP, SERVER_PORT);
    printf("Enter the file name to download: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);       
    send(clientSocket, buffer, strlen(buffer), 0) ;    
    FILE *file = fopen("received_file", "wb");       
    while ((bytesRead = recv(serverSocket, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytesRead, file);
    }
    fclose(file);
     printf("File received successfully.\n");
    close(clientSocket);    
    return 0;
}

server side program----------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 8888
int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[MAX_BUFFER_SIZE];    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0))   ;  
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));          
    listen(serverSocket, 1) ;    
    printf("Server is listening on port %d...\n", SERVER_PORT);
        while (true) {
clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen));                 
        printf("Client connected ");
        
        ssize_t recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);              
          printf("Received file name from client: %s\n", buffer);
        FILE *file = fopen(buffer, "rb");        
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) 
        send(clientSocket, buffer, bytesRead, 0) ;
        fclose(file);        
        printf("File sent to the client.\n");        
        close(clientSocket);
    }
    close(serverSocket);    
    return 0;
}
