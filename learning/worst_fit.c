//step 1: start the program (not working)
#include<stdio.h>
void main()
{
    // Step 2: declare the necessary variables
    int blockSize[20], processSize[20], numOfBlocks, numOfprocess, allocation[20], i,j;

    // step 3: take the necessary inputs
    printf("Enter the number of blocks: ");// 3.1 number of blocks
    scanf("%d",&numOfBlocks);

    printf("Enter the size of each block: "); // 3.2 size of block
    for (i = 0; i < numOfBlocks; i++)
    {
        scanf("%d",&blockSize[i]);
    }

    printf("Enter the number of process: ");// 3.3 number of process
    scanf("%d",&numOfprocess);

    printf("Enter the size of each process: "); // 3.4 size of process and make alloction = -1
    for (i = 0; i < numOfprocess; i++)
    {
        scanf("%d",&processSize[i]);
        allocation[i] = -1;
    }    

    //step 4: start allocating
    for (i = 0; i < numOfprocess; i++)
    {
        int worstplace = -1;
        for (j = 0; j < numOfBlocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstplace == -1)
                {
                    worstplace = j;
                }
                else if (blockSize[worstplace]<blockSize[j])
                {
                    worstplace = j;
                }
            }
            if (worstplace!= -1)
            {
                allocation[i] = worstplace;
                blockSize[worstplace] -= processSize[i];
            }
            
            
        }
    }

    // step 5: print the output
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < numOfprocess; i++)
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
    
}