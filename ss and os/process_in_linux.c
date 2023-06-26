#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main( ){
   pid_t child_pid;
   child_pid = fork (); 
   if (child_pid < 0) {
      printf("fork failed");
      return 1;
   } else if (child_pid == 0) {
      printf ("child process successfully created!\n");
      printf ("child_PID = %d,parent_PID = %d\n", getpid(), getppid( ) );
   }
 else {
      wait(NULL);
      printf ("parent process successfully created!\n");
      printf ("child_PID = %d, parent_PID = %d", getpid( ), getppid( ) );
   }
   return 0;
}


//-------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t child_pid;
    child_pid = fork();

    if(child_pid < 0)
    {
        printf("fork failed");
    }

    else if(child_pid==0)
    {
        printf("child process successfully created!\n");
        printf("child_pid = %d , parent_pid = %d \n",getpid(),getppid() );
    }

    else
    {
        wait(NULL);
        printf("parent process successfully created! \n");
        printf("child_pid = %d, parent_pid = %d",getpid(),getppid());
    }
    return 0;
}
