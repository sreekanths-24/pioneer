//step 1: start the program (not working)
#include<stdio.h>
struct sjf_cpu
{
    int pid;
    int bt;
    int wt;
    int tat;
}
p[10];

int main()
{
    //step 2: define the required variables
    int i,n,j;
    struct sjf_cpu tmp;
    int total_wt=0, total_tat=0;

    //step 3: take the necessary inputs from the user
    printf("Enter the number of process: ");
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the process id: ");
        scanf("%d",&p[i].pid);

        printf("Enter the burst time: ");
        scanf("%d",&p[i].bt);

    }
    
    //step 4: set first waiting time = 0 and tat = bt
    p[0].wt=0;
    p[0].tat=p[0].bt;

    //step 5: sort according to burst time
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (p[i].bt>p[j].bt)
            {
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
            
        }
        
    }
    
    //step 6: calculate the required outputs
    for (i = 0; i < n; i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt;//waiting time = waiting time of previous + burst time of previous
        p[i].tat=p[i].wt+p[i].bt; //tat = waiting time + burst time
        total_tat += p[i].tat;//total tat = sum of all turn around time
        total_wt += p[i].wt;//total waiting time = sum of all waiting time
    }
    
    //step 7: print the outputs
    printf("\nTotal waiting time: %d", total_wt);
    printf("\nAverage waiting time: %d", total_wt/n);
    printf("\nTotal turn around time: %d",total_tat);
    printf("\nAverage turn around time: %d", total_tat/n);

    
}