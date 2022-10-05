// banker's algorithm for deadlock prevention

// step 1: start the program
#include<stdio.h>
int main()
{
    //step 2: declare the required variables
    int numOfProcess, numOfResourses, i,j,k,y, alloc[20][20], max[20][20], available[50], ind=0;

    //step 3: input the necessary inputs
    printf("Enter the number of process: "); //3.1: number of process
    scanf("%d",&numOfProcess);

    printf("Enter the number of resourses: ");//3.2: numberof resourses
    scanf("%d",&numOfResourses);

    printf("Enter the Allocation matrix: \n");//3.3: allocation matrix
    for(i=0; i<numOfProcess; i++)
    {
        for(j=0; j<numOfResourses; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max matrix: \n");//3.4: max matrix
    for(i=0; i<numOfProcess; i++)
    {
        for(j=0; j<numOfResourses; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available matrix: \n");//3.5 available matrix(numOfResourses)
    for(i=0; i<numOfResourses; i++)
    {
        scanf("%d", &available[i]);
    }

    // step 4: declare the required variables to calculate the need matrix and safe sequence
    int finish[numOfProcess], safeSequence[numOfProcess], work[numOfResourses], need[numOfProcess][numOfResourses]; 

    // step 5: calculate the need matrix    
    for(i=0; i<numOfProcess; i++)
    {
        for(j=0; j<numOfResourses; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // step 6: print the need matrix
    printf("The need matrix is: \n");
    for(i=0; i<numOfProcess; i++)
    {
        printf("\n");
        for(j=0; j<numOfResourses; j++)
        {
            printf("%d",need[i][j]);
        }
    }

    
    //step 7: implement the safety algorithm to find the safe sequence

        //7.1: set work = available
        for(i=0; i<numOfResourses; i++)
        {
            work[i] = available[i];
        }

        //7.2: set finish[i] = false or 0
        for(i=0; i<numOfProcess; i++)
        {
            finish[i] = 0;
        }

        //7.3: find an i such that both finish[i]= 0 and need <= work
        for (k = 0; k < numOfProcess; k++)
        {
            for (i = 0; i < numOfProcess; i++)
            {
                if (finish[i]==0)
                {
                    int flag= 0;
                    for (j = 0; j < numOfResourses; j++)
                    {
                        if (need[i][j]> work[j])
                        {
                            flag = 1;
                            break;
                        }
                        
                    }
                    if (flag == 0)
                    {
                        safeSequence[ind++] = i;
                        for (y = 0; y < numOfResourses; y++)
                        {
                            work[y] += alloc[i][y];
                        }
                        finish[i] = 1;
                        
                    }
                    
                    
                }
                
            }
            
        }
    
    //step 8: print the safe sequence
    printf("\nFollowing is the safe sequence\n");
    for (i = 0; i < numOfProcess; i++)
    {
        printf("P%d", safeSequence[i]);
    }
    // step 9: stop the program

}
