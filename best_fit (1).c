#include<stdio.h>

void main()
{
    int n_process, n_block, p[20], b[20], allocate[20], occupied[20], i, j, smallest=-1, space_rem[20];

    //INPUTS
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

    //SET ALLOCATE AND OCCPIED TO NULL
    for(i=0;i<n_process;i++)
    {
        allocate[i]=-1;
    }
    for(i=0;i<n_block;i++)
    {
        occupied[i]=0;
    }

    //ALLOCATE
    //set largest size for block -1.
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

    //PRINT RESULT
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