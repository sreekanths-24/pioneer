//first fit

#include<stdio.h>

void main()
{
    int n_process, n_block, p[20], b[20], allocate[20], occupied[20], i, j;

    printf("\n\n\t\t\t --- FIRST FIT --- ");
    printf("\n\nEnter the number of process: ");
    scanf("%d", &n_process);
    printf("\nEnter the number of blocks: ");
    scanf("%d", &n_block);
    printf("\n\nEnter the details for each process:-");
    for(i=0;i<n_process;i++)
    {
        printf("\n\t-> Process %d", i);
        printf("\n\tP%d Size: ", i);
        scanf("%d", &p[i]);
    }
    printf("\nEnter the details for each blocks:-");
    for(i=0;i<n_block;i++)
    {
        printf("\n\t-> Block %d", i);
        printf("\n\tB%d Size: ", i);
        scanf("%d", &b[i]);
    }

    for(i=0;i<n_process;i++)
    {
        allocate[i]=-1;
    }
    for(i=0;i<n_block;i++)
    {
        occupied[i]=0;
    }


    for(i=0;i<n_process;i++)
    {
        for(j=0;j<n_block;j++)
        {
            if(p[i] <= b[j] && !occupied[j])
            {
                occupied[j]=1;
                allocate[i]=j;
                break;
            }
        }
    }

    printf("\n\n\tProcess No.\tProcess Size\tAllocated Block No.\n");
    for(i=0;i<n_process;i++)
    {
        printf("\t\t%d\t\t%d\t\t", i, p[i]);
        if(allocate[i] != -1)
            printf("%d\n", allocate[i]);
        else
            printf("Unallocated\n");
    }
}
//----------------------------------------------------------------------------------------------------------------
// best fit

#include<stdio.h>

void main()
{
    int n_process, n_block, p[20], b[20], allocate[20], occupied[20], i, j, smallest=-1, space_rem[20];

    
    printf("\n\n\t\t\t --- BEST FIT --- ");
    printf("\n\nEnter the number of process: ");
    scanf("%d", &n_process);
    printf("\nEnter the number of blocks: ");
    scanf("%d", &n_block);
    printf("\n\nEnter the details for each process:-");
    for(i=0;i<n_process;i++)
    {
        printf("\n\t-> Process %d", i);
        printf("\n\tP%d Size: ", i);
        scanf("%d", &p[i]);
    }
    printf("\nEnter the details for each blocks:-");
    for(i=0;i<n_block;i++)
    {
        printf("\n\t-> Block %d", i);
        printf("\n\tB%d Size: ", i);
        scanf("%d", &b[i]);
        space_rem[i]=b[i];
    }

    for(i=0;i<n_process;i++)
    {
        allocate[i]=-1;
    }
    for(i=0;i<n_block;i++)
    {
        occupied[i]=0;
    }

    space_rem[-1]=10000;
    for(i=0;i<n_process;i++)
    {
        for(j=0;j<n_block;j++)
        {
            if(space_rem[smallest]>space_rem[j] && space_rem[j]>=p[i])
            {
                smallest=j;
            }
        }
        if(space_rem[smallest] >= p[i])
        {
            space_rem[smallest]=space_rem[smallest]-p[i];
            allocate[i]=smallest;
        }
        smallest=-1;
    }

    printf("\n\n\tProcess No.\tProcess Size\tAllocated Block No.\n");
    for(i=0;i<n_process;i++)
    {
        printf("\t\t%d\t\t%d\t\t", i, p[i]);
        if(allocate[i] != -1)
            printf("%d\n", allocate[i]);
        else
            printf("Unallocated\n");
    }


}

//-----------------------------------------------------------------------------------------------------------------
//worst fit

#include <stdio.h>

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{

    int allocation[processes];
    int occupied[blocks];
    int i,j;
    for( i = 0; i < processes; i++){
        allocation[i] = -1;
    }

    for( i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for ( i=0; i < processes; i++)
    {
        int indexPlaced = -1;
        for( j = 0; j < blocks; j++)
        {
            if(blockSize[j] >= processSize[i] && !occupied[j])
            {
                    if (indexPlaced == -1)
                    indexPlaced = j;
                    else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            blockSize[indexPlaced] -= processSize[i];
        } }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for ( i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    int blockSize[20];
    int processSize[20];
    int i,n,m;
    printf("enter the number of blocks:");
    scanf("%d",&n);
        for(i=0;i<n;i++)
    {
    printf("enter the %d block size:",i);
    scanf("%d",&blockSize[i]);
    }
    printf("enter the no of process:");
    scanf("%d",&m);
        for(i=0;i<m;i++)
        {         printf("enter the %d size of process:",i);

                scanf("%d",&processSize[i]);
        }
   implimentWorstFit(blockSize,n,processSize,m);
    return 0;

}