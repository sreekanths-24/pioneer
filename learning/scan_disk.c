//step 1: start the program
#include<stdio.h>
#include<stdlib.h>
void main()
{
    //step 2: declare the necassery variables
    int request[100],i,j,n,TotalHeadMovement=0,initial,size,move;

    //step 3: take the necassery inputs
    printf("Enter the number of requests: ");//3.1 number of requests
    scanf("%d",&n);

    printf("Enter the request sequence: ");//3.2 request sequence
    for (i = 0; i < n; i++)
    {
        scanf("%d",&request[i]);
    }
    
    printf("Enter initial head positions: ");//3.3 initial head position
    scanf("%d",&initial);

    printf("Enter the total disk size: "); //3.4 total disk size
    scanf("%d",&size);

    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d",&move);

    //step 4: sort the request array
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (request[j]>request[j+1])
            {
                int temp;
                temp = request[j];
                request[j]=request[j+1];
                request[j+1]=temp;
            }  
        }  
    }
    
    //step 5: initialise the index variable and check if the index is < request
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial<request[i])
        {
            index=i;
            break;
        }
        
    }
    
    //step 6: if movement is towards higher value
    if (move==1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMovement = TotalHeadMovement + abs(request[i]-initial);
            initial=request[i];
        }

        //6.1 last movement for max size
        TotalHeadMovement = TotalHeadMovement + abs(size-request[i-1]-1);
        initial = size-1;
        for (i = index-1; i >= 0; i--)
        {
            TotalHeadMovement = TotalHeadMovement + abs(request[i]-initial);
            initial=request[i];
        }
    }
    //step 7: if movement is towards lower value
    else
    {
        for (i = index-1; i >= 0; i--)
        {
            TotalHeadMovement = TotalHeadMovement + abs(request[i]-initial);
            initial=request[i];
        }

        //7.1 last movement for min size
        TotalHeadMovement = TotalHeadMovement + abs(request[i+1]-0);
        initial = 0;
        for (i = index; i < n; i++)
        {
            TotalHeadMovement = TotalHeadMovement + abs(request[i]-initial);
            initial=request[i];
        }        
    }
    //step 8: print the output
    printf("The total head movment is: %d",&TotalHeadMovement);
}