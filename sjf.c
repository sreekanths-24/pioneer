#include <stdio.h>
//SJF (NON-PREEMPTIVE)

void main()
{
    int i, j, n, p[10], b[10], a[10], temp, tat[10], wt[10], ft[10], st[10], gt[10], count;
    float avgtat=0, avgwt=0;
    //n     - number of process
    //p     - process number
    //b     - burst time
    //a     - arrival time
    //tat   - turn around time
    //wt    - waiting time
    //ft    - finish time
    //st    - starting time
    //gt    - garnt chart

    printf("\n\n\t--- CPU SCHEDULING SJF ---");
    printf("\n\nEnter the number of process: ");
    scanf("%d", &n);

    printf("\nEnter the details\n");
    for(i=0;i<n;i++)
    {
        printf("-> Process %d\n", i);
        p[i]=i;
        printf("Burst Time: ");
        scanf("%d", &b[i]);
        printf("Arrival Time: ");
        scanf("%d", &a[i]);
        printf("\n");
    }

    //SORT ACCORDING TO ARRIVAL TIME
    //IF ARRIVAL TIMES ARE EQUAL, THEN SORT THEM ACCORDING TO BURST TIME
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
            else if(a[j] == a[j+1])
            {
                if(b[j] > b[j+1])
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
    }

    //SORT AGAIN BASED ON BURST IF ALL PROCESS HAS ALREADY ARRIVED
    count=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<=count && b[i]>b[j] && a[j]<=count)
            {
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;

                    temp=b[j];
                    b[j]=b[i];
                    b[i]=temp;

                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
            }
        }
        count=count+b[i];
    }

    //CALCULATE
    for(i=0;i<n;i++)
    {
        st[i]=a[i];
        if(i > 0)
        {
            if(a[i] > ft[i-1])
                st[i]=a[i];
            else if(a[i] < ft[i-1])
                st[i]=ft[i-1];
            else
                st[i]=a[i];
        }

        ft[i]=st[i]+b[i];
        gt[i]=ft[i]-st[i];

        tat[i]=ft[i]-a[i];
        wt[i]=tat[i]-b[i];

        avgtat=avgtat+tat[i];
        avgwt=avgwt+wt[i];
    }

    avgtat=avgtat/n;
    avgwt=avgwt/n;

    //PRINT
    printf("\n\n\tProcess id|\tArrival Time|\tBurst Time|\tWaiting Time|\tTurnaround Time|\tGarnt chart|\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d - %d\n", p[i], a[i], b[i], wt[i], tat[i], st[i], ft[i]);
    }
    printf("\n\nAverage Turnaround Time: %f", avgtat);
    printf("\n\nAverage Waiting Time: %f\n\n", avgwt);
}