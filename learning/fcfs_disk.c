//step 1: start the program
#include<stdio.h>
#include<stdlib.h>

void main()
{
    //step 2: declare the required variables
    int request[100],i,n,TotalHeadMovement=0,initial;

    //step 3: take the necassery inputs
    printf("Enter the number of Requests: ");// 3.1 number of requests
    scanf("%d",&n);

    printf("Enter the request sequence: ");// 3.2 request sequence
    for (i = 0; i < n; i++)
    {
        scanf("%d",&request[i]);
    }
    
    printf("Enter the initial head sequence: ");// 3.3 initial head sequence
    scanf("%d",&initial);

    // step 4: logic for fcfs
    for (i = 0; i < n; i++)
    {
        TotalHeadMovement = TotalHeadMovement + abs(request[i]-initial);
        initial=request[i];
    }
    
    //step 5: print the total head movement
    printf("Total Head Movement = %d",TotalHeadMovement);
}