//step 1: start the program
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // step 2: declare the required variables
    int i,j,n, bt[10], p[10], compt[10], wt[10], tat[10], temp1, temp2;
    float sumwt=0, sumtat=0;

    // step 3: enter the necessary inputs
    printf("Enter the number of processes: ");//3.1 number of process
    scanf("%d", &n);

    printf("Enter the burst time of each process\n");// 3.2 burst time
    for (i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }

    printf("Enter the priority of each process\n");//3.3 priority
    for (i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }

    //step 4: sort according to priority
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (p[i]>p[j])
            {
                temp1=bt[i];
                bt[i]=bt[j];
                bt[j]=temp1;

                temp2=p[i];
                p[i]=p[j];
                p[j]=temp2;  
            }
            
        }
        
    }

    //step 5: completion time = burst time and waiting time of first process =0
    wt[0]=0;
    compt[0]=bt[0];

    //step 6: calculate the outputs
    for (i = 1; i < n; i++)
    {
        compt[i]=bt[i]+compt[i-1];
    }
    for (i = 0; i < n; i++)
    {
        tat[i]=compt[i];
        wt[i]=tat[i]-bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }

    //step 7: calculate the outputs
    printf("Total Waiting time: %f\n",sumwt);
    printf("Average Waiting time: %f\n",sumwt/n);
    printf("Total Turn Around time: %f\n",sumtat);
    printf("Average Turn Around: %f\n",sumtat/n);
    
}