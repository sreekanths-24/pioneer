/*#include<stdio.h>
void main()
{
    int i=0,j=0,a[20],b[20],p[20],n=0,g[20],t[20],w[20];
    float avgw=0,avgt=0;

    printf("Enter the number of process: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("process id : ");
        scanf("%d",&p[i]);

        printf("burst time : ");
        scanf("%d",&b[i]);

        printf("arrival time : ");
        scanf("%d",&a[i]);
    }

    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

                temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    
    g[0] = 0;
    for(i=0;i<n;i++)
    {
        g[i+1] = g[i]+b[i];
    }

    for(i=0;i<n;i++)
    {
        t[i] = g[i+1]-a[i];
        w[i] = t[i] - b[i];
        avgw += w[i];
        avgt += t[i];
    }
    avgw = avgw/n;
    avgt = avgt/n;

    printf("pid\tarrival time\tburst time\twaiting time\tturn around time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],a[i],b[i],w[i],t[i]);
    }
    printf("\navg wt = %f",avgw);
    printf("\navg tat = %f",avgt);
}


//step 1: start the program
#include<stdio.h>

void main()
{
    //step 2: declare the required variables
    int n, p[20], a[20], b[20], i, j, temp=0, gbefore[20], gafter[20], wt[20], tat[20];
    float avgtat=0, avgwt=0;

    //step 3: take the required inputs from the user
    printf("\n\n\t\t\t --- FCFS SCHEDULING --- ");
    printf("\n\nEnter the number of process: ");
    scanf("%d", &n);
    printf("Enter the details for each process:-");
    for(i=0;i<n;i++)
    {
        p[i]=i;
        printf("\n\t-> Process %d", i);
        printf("\n\tBurst Time: ");
        scanf("%d", &b[i]);
        printf("\tArrival Time: ");
        scanf("%d", &a[i]);
    }

    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    
    temp=0;
    for(i=0;i<n;i++)
    {
        gbefore[i]=temp+a[i];
        gafter[i]=gbefore[i]+b[i];
        if(a[i+1] >= gafter[i])
            temp=0;
        else if(a[i+1] < gafter[i])
            temp=gafter[i]-a[i+1];
    }


    
    for(i=0;i<n;i++)
    {
        tat[i]=gafter[i]-a[i];
        wt[i]=tat[i]-b[i];

        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    avgtat=avgtat/n;
    avgwt=avgwt/n;

    
    printf("\n\n");
    printf("\tProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\t\tGantt Chart\n");
    for(i=0;i<n;i++)
    {
        printf("\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d-%d\n", p[i], a[i], b[i], wt[i], tat[i], gbefore[i], gafter[i]);
    }
    printf("\nAverage Turnaroud Time: %f", avgtat);
    printf("\nAverage Waiting Time: %f\n\n", avgwt);

}*/

//step 1: start the program (not working)
#include<stdio.h>
#include<stdlib.h>

// step 2: define a structure
struct fcfs_cpu
{
    int pid;
    int bt;
    int wt;
    int tat;
}
p[10];

int main()
{
    // step 3: declare the necessary variables
    int i=0,numberOfProcess=0;
    struct fcfs_cpu temp;
    int total_tat=0, total_wt=0;

    // step 4: take the input from the user
    printf("Enter the number of process: "); //4.1 number of process
    scanf("%d",&numberOfProcess);

    for (i = 0; i < numberOfProcess; i++) // 4.2 burst time
    {
        p[i].pid = 1;
        printf("Burst time of the process: \n");
        scanf("%d",&p[i].bt);
    }
    
    // step 5: set the waiting time of first process to 0 and tat = bt
    p[0].wt=0;
    p[0].tat=p[0].bt;

    //step 6: calculate the required outputs
    for (i = 0; i < numberOfProcess; i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt;//waiting time = waiting time of previous + burst time of previous
        p[i].tat=p[i].wt+p[i].bt; //tat = waiting time + burst time
        total_tat += p[i].tat;//total tat = sum of all turn around time
        total_wt += p[i].wt;//total waiting time = sum of all waiting time
    }
    
    //step 7: print the outputs
    printf("\nTotal waiting time: %d", total_wt);
    printf("\nAverage waiting time: %d", total_wt/numberOfProcess);
    printf("\nTotal turn around time: %d",total_tat);
    printf("\nAverage turn around time: %d", total_tat/numberOfProcess);
}
//step 8: stop the program */