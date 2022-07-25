#include<stdio.h>

void main()
{
    int n, p[20], a[20], b[20], i, j, temp=0, gbefore[20], gafter[20], wt[20], tat[20];
    float avgtat=0, avgwt=0;

    //INPUTS
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

    //SORT PROCESSES BASED ON ARRIVAL TIME
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

    //GANTT CHART
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


    //CALCULATIONS
    for(i=0;i<n;i++)
    {
        tat[i]=gafter[i]-a[i];
        wt[i]=tat[i]-b[i];

        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    avgtat=avgtat/n;
    avgwt=avgwt/n;

    //PRINT
    printf("\n\n");
    printf("\tProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\t\tGantt Chart\n");
    for(i=0;i<n;i++)
    {
        printf("\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d-%d\n", p[i], a[i], b[i], wt[i], tat[i], gbefore[i], gafter[i]);
    }
    printf("\nAverage Turnaroud Time: %f", avgtat);
    printf("\nAverage Waiting Time: %f\n\n", avgwt);

}