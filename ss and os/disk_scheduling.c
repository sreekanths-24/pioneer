//disk scheduling
//fcfs

#include<stdio.h>
#include<stdlib.h>

void main()
{
    
    int request[100],i,n,TotalHeadMovement=0,initial;

    
    printf("Enter the number of Requests: ");
    scanf("%d",&n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&request[i]);
    }
    
    printf("Enter the initial head sequence: ");
    scanf("%d",&initial);

    
    for (i = 0; i < n; i++)
    {
        TotalHeadMovement = TotalHeadMovement + abs(request[i]-initial);
        initial=request[i];
    }
    
    
    printf("Total Head Movement = %d",TotalHeadMovement);
}

//another code for fcfs

  #include<stdio.h>
  void main(){
   int ioq[20],i,n,ihead,tot;
   float seek=0,avgs;

   printf("Enter the number of requests\t:");
   scanf("%d",&n);
   printf("Enter the initial head position\t:");
   scanf("%d",&ihead);
   ioq[0] = ihead;
   ioq[n+1] =0;
   printf("Enter the I/O queue requests \n");
   for(i=1;i<=n;i++){
   scanf("%d",&ioq[i]);
   }
   ioq[n+1] =ioq[n];
   printf("\nOrder of request served\n");
   for(i=0;i<=n;i++){

   tot = ioq[i+1] - ioq[i];
   if(tot < 0)
   tot = tot * -1;
   seek += tot;
   
   printf("%d --> ",ioq[i]);

   }
   avgs = seek/(n);
   printf("\nTotal Seek time\t\t: %.2f",seek);
   printf("\nAverage seek time\t: %.2f\n\n",avgs);
  }

//===============================================================================================================
  //scan
  #include<stdio.h>
  void main()
  {
   int ioq[20],i,n,j,ihead,temp,scan,tot;
   float seek=0,avgs;

   printf("Enter the number of requests\t:");
   scanf("%d",&n);
   printf("Enter the initial head position\t:");
   scanf("%d",&ihead);
   ioq[0] = ihead;
   ioq[1] = 0;
   n += 2;
   printf("Enter the I/O queue requests \n");
   for(i=2;i<n;i++){
   scanf("%d",&ioq[i]);
   }

   for(i=0;i<n-1;i++){
   for(j=0;j<n-1;j++)
   {

   if(ioq[j] > ioq[j+1]){

   temp = ioq[j];
   ioq[j] = ioq[j+1];
   ioq[j+1] = temp;

   }

   }
   }
   ioq[n]=ioq[n-1];
   for(i=0;i<n;i++){

   if(ihead == ioq[i]){

   scan = i;
   break;

   }

   }

   printf("\nOrder of request served\n\n");
   tot = 0;
   for(i=scan;i>=0;i--){
   tot = ioq[i] - ioq[i-1]; 
   if(i==0) 
   tot=ioq[i]-ioq[scan+1];
   if(tot < 0)
   tot = tot * -1;
   
   printf("%d\t%d\n",ioq[i],tot);
   }


   for(i=scan+1;i<n;i++){
   tot = ioq[i+1] - ioq[i];
   if(tot < 0)
   tot = tot * -1;
   
   printf("%d\t%d\n",ioq[i],tot);
   }
   seek = ihead + ioq[n-1];

   avgs = seek/(n-2);
   printf("\n\nTotal Seek time\t\t: %.2f",seek);
   
  }

//=================================================================================================================
//c scan
  #include<stdio.h>
  void main()
  {
   int ioq[20],i,n,j,ihead,itail,temp,scan,tot=0;
   float seek=0,avgs;

   printf("Enter the number of requests\t: ");
   scanf("%d",&n);
   ioq[0] = 0;
   printf("Enter the initial head position\t: ");
   scanf("%d",&ihead);
   ioq[1] = ihead;
   printf("Enter the maximum track limit\t: ");
   scanf("%d",&itail);
   ioq[2] = itail;
   n += 3;

   printf("Enter the I/O queue requests \n");
   for(i=3;i<n;i++){
   scanf("%d",&ioq[i]);
   }


   for(i=0;i<n-1;i++){
   for(j=0;j<n-1;j++)
   {

   if(ioq[j] > ioq[j+1]){

   temp = ioq[j];
   ioq[j] = ioq[j+1];
   ioq[j+1] = temp;

   }

   }
   }

   for(i=0;i<n+1;i++){

   if(ihead == ioq[i]){

   scan = i;
   break;

   }

   }

   i = scan;
   temp = n;

   printf("\nOrder of request served\n");
   printf("\n");

   while(i != temp){

   if(i < temp-1){
   tot = ioq[i+1] - ioq[i];

   if(tot < 0)
   tot = tot * -1;
   seek += tot;
   }
   printf("%d --> ",ioq[i]);
   i++;

   if(i == n){
   i = 0;
   temp = scan;
   seek += itail;
   }

   }

   avgs = seek/(n-3);
   printf("\n\nTotal Seek time\t\t: %.2f",seek);
   printf("\nAverage seek time\t: %.2f\n\n",avgs);
  }
