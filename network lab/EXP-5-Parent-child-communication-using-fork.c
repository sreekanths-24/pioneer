#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int pipefd[2];
    pid_t pid;
    char message[] = "Hello, child!";
    char buffer[20];    
    pipe(pipefd) ;    
    pid = fork();
    if (pid == 0) {
        close(pipefd[1]);        
        read(pipefd[0], buffer, sizeof(buffer));        
        printf("Child received message: %s\n", buffer);        
        close(pipefd[0]);        
        exit();
    } else {
        close(pipefd[0]);        
        write(pipefd[1], message, sizeof(message));        
        close(pipefd[1]);        
        wait(NULL);        
        printf("Parent sent message to child.\n");        
        exit();
    }    
    return 0;
}.
