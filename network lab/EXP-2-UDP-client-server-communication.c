server side

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUFFER_SIZE];
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0))     
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);    
    inet_pton(AF_INET, SERVER_IP, &(serverAddr.sin_addr)) 
        printf("Enter data to send : ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);                 
    sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) ;                
        printf("Data sent to server.\n");        
        struct sockaddr_in serverResponseAddr;
        socklen_t serverResponseAddrLen = sizeof(serverResponseAddr);        
        ssize_t recvLen = recvfrom(clientSocket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&serverResponseAddr, &serverResponseAddrLen);                   
        printf("Server response: %s\n", buffer);
    close(clientSocket);    
    return 0;
}

client side ----------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUFFER_SIZE];    
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);          
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);    
    inet_pton(AF_INET, SERVER_IP, &(serverAddr.sin_addr));    
       printf("Enter data to send : ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);            
    sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));                   
        printf("Data sent to server.\n");        
        struct sockaddr_in serverResponseAddr;
        socklen_t serverResponseAddrLen = sizeof(serverResponseAddr);        
        ssize_t recvLen = recvfrom(clientSocket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&serverResponseAddr, &serverResponseAddrLen);              
        printf("Server response: %s\n", buffer);    
    close(clientSocket);    
    return 0;
}
