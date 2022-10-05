//step 1: start the program
#include<stdio.h>

int main()
{
    //step 2: declare the necassery variables
    int i,j,n,time,remain,flag=0,ts;//ts = time slice
    int sum_wait=0, sum_tat=0,at[10],bt[10],rt[10];

    //step 3: take the inputs
    printf("Enter the number of process: ");// 3.1 number of process
    scanf("%d",&n);

    remain=n;//3.2 set remain = n

    for (i = 0; i < n; i++)
    {
        
        printf("Enter the arrival time of process P%d: ", i+1);
        scanf("%d",&at[i]);
        
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process P%d: ", i+1);
        scanf("%d",&bt[i]);
    }
    
    
    for (i = 0; i < n; i++)
    {
        rt[i]=bt[i];
    }
    
    //step 4: calculate the output
    printf("Enter the time slice: ");
    scanf("%d",&ts);

    for (time=0,i=0;remain!=0;)
    {
        if (rt[i]<=ts && rt[i]>0)
        {
            time +=rt[i];
            rt[i]=0;
            flag=1;
        }
        else if (rt[i]>0)
        {
            rt[i] -= ts;
            time += ts;
        }
        if (rt[i]==0 && flag ==1)
        {
            remain--;
            sum_wait += time-at[i]-bt[i];
            sum_tat += time-at[i];
            flag=0;
        }
        if (i==n-1)
        {
            i=0;

        }
        else if (at[i+1]<= time)
        {
            i++;
        }
        else
        {
            i=0;
        }    
    }
    

    //step 5: print the output
    printf("\nTotal Waiting time = %d\n",sum_wait);
    printf("\nAverage Waiting time = %d\n",sum_wait/n);
    printf("\nTotal Turnaround time = %d\n",sum_tat);
    printf("\nAverage Turnaround time = %d\n",sum_tat/n);
    return 0;

}