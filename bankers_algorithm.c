//dead lock banker's algorithm

// banker's algorithm for deadlock prevention

//step 1: start the program
//step 2: declare the required variables
//step 3: input the necessary inputs
        //3.1: number of process
        //3.2: numberof resourses
        //3.3: allocation matrix
        //3.4: max matrix
        //3.5 available matrix
// step 4: calculate the need matrix    
// step 5: print the need matrix
//step 6: implement the safety algorithm to find the safe sequence
        //6.1: set work = available
        //6.2: set finish[i] = false or 0
        //6.3: find an i such that both finish[i]= 0 and need <= work
//step 7: print the safe sequence
             
#include<stdio.h>
int main()
{
    int numOfProcess, numOfResourses, i,j,k,y, alloc[20][20], max[20][20], available[50], ind=0;
    int finish[numOfProcess], safeSequence[numOfProcess], work[numOfResourses], need[numOfProcess][numOfResourses]; 

    printf("Enter the number of process: "); 
    scanf("%d",&numOfProcess);

    printf("Enter the number of resourses: ");
    scanf("%d",&numOfResourses);

    printf("Enter the Allocation matrix: \n");
    for(i=0; i<numOfProcess; i++)
    {
        for(j=0; j<numOfResourses; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max matrix: \n");
    for(i=0; i<numOfProcess; i++)
    {
        for(j=0; j<numOfResourses; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available matrix: \n");
    for(i=0; i<numOfResourses; i++)
    {
        scanf("%d", &available[i]);
    }

    for(i=0; i<numOfProcess; i++)
    {
        for(j=0; j<numOfResourses; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("The need matrix is: \n");
    for(i=0; i<numOfProcess; i++)
    {
        printf("\n");
        for(j=0; j<numOfResourses; j++)
        {
            printf("%d",need[i][j]);
        }
    }

        for(i=0; i<numOfResourses; i++)
        {
            work[i] = available[i];
        }

        for(i=0; i<numOfProcess; i++)
        {
            finish[i] = 0;
        }

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
    
    printf("\nFollowing is the safe sequence\n");
    for (i = 0; i < numOfProcess-1; i++)
    {
        printf("P%d", safeSequence[i]);
    }
    

}

//---------------------------------------------------------------------------------------------------------------

        #include<stdio.h>
        struct pro{
        int all[10],max[10],need[10];
        int flag;
        };
        int i,j,pno,r,nr,id,k=0,safe=0,exec,count=0,wait=0,max_err=0;
        struct pro p[10];
        int aval[10],seq[10];
        void safeState()
        {
        while(count!=pno){
        safe = 0;
        for(i=0;i<pno;i++){
        if(p[i].flag){
        exec = r;
        for(j=0;j<r;j++)
        {
        if(p[i].need[j]>aval[j]){
        exec =0;
        }
        }
        if(exec == r){
        for(j=0;j<r;j++){
        aval[j]+=p[i].all[j];
        }
        p[i].flag = 0;
        seq[k++] = i;
        safe = 1;
        count++;
        }
        }
        }
        if(!safe)
        {
        printf("System is in Unsafe State\n");
        break;
        }
        }
        if(safe){
        printf("\n\nSystem is in safestate \n");
        printf("Safe State Sequence \n");
        for(i=0;i<k;i++)
        printf("P[%d] ",seq[i]);
        printf("\n\n");
        }
        }
        void reqRes(){
        printf("\nRequest for new Resourses");
        printf("\nProcess id ? ");
        scanf("%d",&id);
        printf("Enter new Request details ");
        for(i=0;i<r;i++){
        scanf("%d",&nr);
        if( nr <= p[id].need[i])
        {
        if( nr <= aval[i]){
        aval[i] -= nr;
        p[id].all[i] += nr;
        p[id].need[i] -= nr;
        }
        else
        wait = 1;
        }
        else
        max_err = 1;
        }
        if(!max_err && !wait)
        safeState();
        else if(max_err){
        printf("\nProcess has exceeded its maximum usage \n");
        }
        else{
        printf("\nProcess need to wait\n");
        }
        }
        void main()
        {
        printf("Enter no of process ");
        scanf("%d",&pno);
        printf("Enter no. of resourses ");
        scanf("%d",&r);
        printf("Enter Available Resourse of each type ");
        for(i=0;i<r;i++){
        scanf("%d",&aval[i]);

        }
        printf("\n\n---Resourse Details---");
        for(i=0;i<pno;i++){
        printf("\nResourses for process %d\n",i);
        printf("\nAllocation Matrix\n");
        for(j=0;j<r;j++){
        scanf("%d",&p[i].all[j]);
        }
        printf("Maximum Resourse Request \n");
        for(j=0;j<r;j++){
        scanf("%d",&p[i].max[j]);
        }
        p[i].flag = 1;
        }
        
        for(i=0;i<pno;i++){
        for(j=0;j<r;j++){
        p[i].need[j] = p[i].max[j] - p[i].all[j];
        }
        }
        
        printf("\nProcess Details\n");
        printf("Pid\t\tAllocattion\t\tMax\t\tNeed\n");
        for(i=0;i<pno;i++)
        {
        printf("%d\t\t",i);
        for(j=0;j<r;j++){
        printf("%d ",p[i].all[j]);
        }
        printf("\t\t");
        for(j=0;j<r;j++){
        printf("%d ",p[i].max[j]);
        }
        printf("\t\t");
        for(j=0;j<r;j++){
        printf("%d ",p[i].need[j]);
        }
        printf("\n");
        }
        
        safeState();
        int ch=1;
        do{
        printf("Request new resourse ?[0/1] :");
        scanf("%d",&ch);
        if(ch)
        reqRes();
        }while(ch!=0);
        
        }