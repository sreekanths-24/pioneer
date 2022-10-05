#include<stdio.h>
//step 1: start the program
void main()
{

    //step 2: define the required variables
    int fragment[20], numOfBlocks, numOfProcess, blocks[20], process[20],i,j,temp,lowest=9999;
    static int blockArray[20], processArray[20];

    //step 3: input the necessary inputs
    printf("Enter the number of blocks: ");// 3.1 number of blocks
    scanf("%d",&numOfBlocks);

    printf("Enter the block sizes: \n");//3.2 block sizes
    for (i = 0; i < numOfBlocks; i++)
    {
        scanf("%d",&blocks[i]);
    } 

    printf("Enter the number of processes: ");//3.3 number of processes
    scanf("%d",&numOfProcess);

    printf("Enter the process sizes: \n");//3.4 process sizes
    for (i = 0; i < numOfProcess; i++)
    {
        scanf("%d",&process[i]);
    } 

    //step 4: calculate the bestfit
    for (i = 0; i < numOfProcess; i++)
    {
        for (j = 0; j < numOfBlocks; j++)
        {
            if (blockArray[j] != 1)
            {
                temp = blocks[j]-process[j];
                if (temp>=0)
                {
                    if (lowest>temp)
                    {
                        processArray[i] = j;
                        lowest = temp;
                    }
                    
                }
                
            }
            
        }
        fragment[i] = lowest;
        blockArray[processArray[i]]=1;
        lowest=10000;
        
    }
    
    //step 5: print the output
    printf("\nProcess num\tProcess size\tBlock num\tBlock Size\tfragment");
    for (i = 1; i < numOfProcess && processArray[i]!=0; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,process[i],processArray[i],blocks[processArray[i]],fragment[i]);
    }
    // step 6: stop the program
}