//------------------------------------------------------------------------------------------------------------

//fcfs scheduling 

#include<stdio.h>

void main()
{
    int n, p[20], a[20], b[20], i, j, temp=0, gbefore[20], gafter[20], wt[20], tat[20];
    float avgtat=0, avgwt=0;

    
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

}

//another code for fcfs

#include<stdio.h>
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


//-----------------------------------------------------------------------------------------------------------------

//sjf

#include<stdio.h>
void main()
{
	int i=0,j=0,p[i],b[i],g[20],w[20],t[20],a[20],n=0,m;
	int k=1,min=0,btime=0;
	float avgw=0,avgt=0;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nProcess id : ");
		scanf("%d",&p[i]);

		printf("Burst Time : ");
		scanf("%d",&b[i]);

		printf("Arrival Time: ");
		scanf("%d",&a[i]);
	}
	
	int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
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
	
	for(i=0;i<n;i++)
	{
		btime=btime+b[i];
		min=b[k];
		for(j=k;j<n;j++)
		{
			if(btime >= a[j] && b[j]<min)
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;

				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;

				temp=p[j];
				p[j]=p[j-1];
				p[j-1]=temp;
			}
		}
		k++;
	}
	g[0]=a[0];
	for(i=0;i<n;i++)
	{
		g[i+1]=g[i]+b[i];
		if(g[i]<a[i])
			g[i]=a[i];
	}
	for(i=0;i<n;i++)
	{
		
		
		t[i]=g[i+1]-a[i];
		w[i]=t[i]-b[i];
		avgw+=w[i];
		avgt+=t[i];
	}
	avgw=avgw/n;
	avgt=avgt/n;
	printf("pid\tBrustTime\tGantChart\tWaiting time\t\tTurnarround Time\n");
	for(i=0;i<n;i++)
	{
		printf(" %d\t %d\t\t%d-%d\t\t%d\t\t\t%d\n",p[i],b[i],g[i],g[i+1],w[i],t[i]);
	}
	printf("\nAverage waiting time %f",avgw);
	printf("\nAverage turnarround time %f\n",avgt);
	
}


//another code for sjf scheduling

#include <stdio.h>

int main()

{

    int A[100][4];

    int i, j, n, total = 0, index, temp;

    float avg_wt, avg_tat;

    printf("Enter number of process: ");

    scanf("%d", &n);

    printf("Enter Burst Time:\n");


    for (i = 0; i < n; i++) {

        printf("P%d: ", i + 1);

        scanf("%d", &A[i][1]);

        A[i][0] = i + 1;

    }

    

    for (i = 0; i < n; i++) {

        index = i;

        for (j = i + 1; j < n; j++)

            if (A[j][1] < A[index][1])

                index = j;

        temp = A[i][1];

        A[i][1] = A[index][1];

        A[index][1] = temp;

 

        temp = A[i][0];

        A[i][0] = A[index][0];

        A[index][0] = temp;

    }

    A[0][2] = 0;

    

    for (i = 1; i < n; i++) {

        A[i][2] = 0;

        for (j = 0; j < i; j++)

            A[i][2] += A[j][1];

        total += A[i][2];

    }

    avg_wt = (float)total / n;

    total = 0;

    printf("P     BT     WT     TAT\n");


    for (i = 0; i < n; i++) {

        A[i][3] = A[i][1] + A[i][2];

        total += A[i][3];

        printf("P%d     %d     %d      %d\n", A[i][0],

               A[i][1], A[i][2], A[i][3]);

    }

    avg_tat = (float)total / n;

    printf("Average Waiting Time= %f", avg_wt);

    printf("\nAverage Turnaround Time= %f", avg_tat);

}


//------------------------------------------------------------------------------------------------------------------

//priority scheduling

#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    int i,j,n, bt[10], p[10], compt[10], wt[10], tat[10], temp1, temp2;
    float sumwt=0, sumtat=0;

    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }

    printf("Enter the priority of each process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }

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

    wt[0]=0;
    compt[0]=bt[0];

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

    printf("Total Waiting time: %f\n",sumwt);
    printf("Average Waiting time: %f\n",sumwt/n);
    printf("Total Turn Around time: %f\n",sumtat);
    printf("Average Turn Around: %f\n",sumtat/n);
    
}

//another code for priority sceduling

#include<stdio.h>
 
struct priority_scheduling {

  
  char process_name;


  int burst_time;


  int waiting_time;


  int turn_around_time;


  int priority;
};

int main() {


  int number_of_process;


  int total = 0;


struct priority_scheduling temp_process;


  int ASCII_number = 65;


  int position;


  float average_waiting_time;


  float average_turnaround_time;

  printf("Enter the total number of Processes: ");

  scanf("%d", & number_of_process);


  struct priority_scheduling process[number_of_process];

  printf("\nPlease Enter the  Burst Time and Priority of each process:\n");


  for (int i = 0; i < number_of_process; i++) {


    process[i].process_name = (char) ASCII_number;

    printf("\nEnter the details of the process %c \n", process[i].process_name);
    printf("Enter the burst time: ");
    scanf("%d", & process[i].burst_time);

    printf("Enter the priority: ");
    scanf("%d", & process[i].priority);


    ASCII_number++;

  }


  for (int i = 0; i < number_of_process; i++) {

    position = i;

    for (int j = i + 1; j < number_of_process; j++) {


      if (process[j].priority > process[position].priority)
        position = j;
    }
 
    temp_process = process[i];
    process[i] = process[position];
    process[position] = temp_process;
  }

  process[0].waiting_time = 0;

  for (int i = 1; i < number_of_process; i++) {
    process[i].waiting_time = 0;
    for (int j = 0; j < i; j++) {

      process[i].waiting_time += process[j].burst_time;
    }

             
    total += process[i].waiting_time;
  }


  average_waiting_time = (float) total / (float) number_of_process;


  total = 0;

  printf("\n\nProcess_name \t Burst Time \t Waiting Time \t  Turnaround Time\n");
  printf("------------------------------------------------------------\n");

  for (int i = 0; i < number_of_process; i++) {

    process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;


    total += process[i].turn_around_time;


    printf("\t  %c \t\t  %d \t\t %d \t\t %d", process[i].process_name, process[i].burst_time, process[i].waiting_time, process[i].turn_around_time);
    printf("\n-----------------------------------------------------------\n");
  }

 
  average_turnaround_time = (float) total / (float) number_of_process;


  printf("\n\n Average Waiting Time : %f", average_waiting_time);


  printf("\n Average Turnaround Time: %f\n", average_turnaround_time);

  return 0;
}

//-----------------------------------------------------------------------------------------------------------------
// round robin
//step 1: start the program
#include<stdio.h>

int main()
{
 
    int i,j,n,time,remain,flag=0,ts;
    int sum_wait=0, sum_tat=0,at[10],bt[10],rt[10];

 
    printf("Enter the number of process: ");
    scanf("%d",&n);

    remain=n;

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
    

 
    printf("\nTotal Waiting time = %d\n",sum_wait);
    printf("\nAverage Waiting time = %d\n",sum_wait/n);
    printf("\nTotal Turnaround time = %d\n",sum_tat);
    printf("\nAverage Turnaround time = %d\n",sum_tat/n);
    return 0;

}

//another code for round robin

#include<stdio.h>
    int main()
    {
      int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Arrival Time:\t");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
      }
      printf("\nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
          total = total + temp[i];
          temp[i] = 0;
          counter = 1;
        }
        else if(temp[i] > 0)
        {
          temp[i] = temp[i] - time_quantum;
          total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
          x--;
          printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i],
          total - arrival_time[i] - burst_time[i]);
          wait_time = wait_time + total - arrival_time[i] - burst_time[i];
          turnaround_time = turnaround_time + total - arrival_time[i];
          counter = 0;
        }
        if(i == limit - 1)
        {
          i = 0;
        }
        else if(arrival_time[i + 1] <= total)
        {
          i++;
        }
        else
        {
          i = 0;
        }
      }
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
    }