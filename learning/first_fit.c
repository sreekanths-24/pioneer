#include<stdio.h>
// step 1: start the program
void main()
{
    // step 2: declare the necessary variables
    int blockSize[10], processSize[10], numOfBlocks, numOfProcess, flags[10], allocation[10],i,j;

    // step 3: make all blocks empty
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    // step 4: input the necessary inputs
    printf("Enter the number of Blocks: "); // 4.1 number of blocks
    scanf("%d",&numOfBlocks);

    printf("Enter the size of each block: ");//4.2 size of each blocks
    for (i = 0; i < numOfBlocks; i++)
    {
        scanf("%d", &blockSize[i]);
    }
    
    printf("Enter the number of Process: "); // 4.3 number of process
    scanf("%d",&numOfProcess);

    printf("Enter the size of each process: ");//4.4 size of each process
    for (i = 0; i < numOfProcess; i++)
    {
        scanf("%d", &processSize[i]);
    }
       
    //step 5: if blocksize >= process size, then allocate block j to p[i]
    for (i = 0; i < numOfProcess; i++)
    {
        for (j = 0; j < numOfBlocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;

                blockSize[j] -= processSize[i];

                break;
            }
            
        }
        
    }

    // step 6: print the outputs
    printf("\nProcess no.\tProcess Size\t Block no.\n");
    for (i = 0; i < numOfProcess; i++)
    {
        printf("%d\t\t%d\t\t",i+1,processSize[i]);
        if (allocation[i] != -1)
        {
            printf("%d\n",allocation[i]+1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
    // step 7: stop the program
}