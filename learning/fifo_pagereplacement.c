 #include<stdio.h> 
  int main() 
  {       
    int total_frames, total_pages, hit = 0;       
    int pages[25], frame[10], arr[25], time[25];       
    int m, n, page, flag, k, minimum_time, temp;       
    printf("Enter Total Number of Pages:\t");       
    scanf("%d", &total_pages);        
    printf("Enter Total Number of Frames:\t");       
    scanf("%d", &total_frames);       
    for(m = 0; m < total_frames; m++)       
    {             
      frame[m] = -1;       
    }       
    for(m = 0; m < 25; m++)       
    {             
      arr[m] = 0;       
    }       
    printf("Enter Values of Reference String\n");       
    for(m = 0; m < total_pages; m++)       
    {             
      printf("Enter Value No.[%d]:\t", m + 1);             
      scanf("%d", &pages[m]);       
    }       
    printf("\n");       
    for(m = 0; m < total_pages; m++)       
    {             
      arr[pages[m]]++;             
      time[pages[m]] = m;             
      flag = 1;             
      k = frame[0];             
      for(n = 0; n < total_frames; n++)             
      {                   
        if(frame[n] == -1 || frame[n] == pages[m])                  
        {                         
          if(frame[n] != -1)                         
          {                               
            hit++;                         
          }                         
          flag = 0;                         
          frame[n] = pages[m];                         
          break; 
        }                   
        if(arr[k] > arr[frame[n]])                   
        {                         
          k = frame[n];                   
        }             
      }             
      if(flag)             
      {                   
        minimum_time = 25;                   
        for(n = 0; n < total_frames; n++)                   
        {                         
          if(arr[frame[n]] == arr[k] && time[frame[n]] < minimum_time)
          {                               
            temp = n;                               
            minimum_time = time[frame[n]];                         
          }                   
        }                   
        arr[frame[temp]] = 0;                   
        frame[temp] = pages[m];             }             
        for(n = 0; n < total_frames; n++)             
        {                   
          printf("%d\t", frame[n]);             
        }             
        printf("\n");       
    }       
    printf("Page Hit:\t%d\n", hit);       
    return 0; 
  }  



/*//step 1: start the program
#include<stdio.h>
void main()
{
    // step 2: declare the required variables
    int i, j, k, f, pf=0, count=0, rs[25], m[20], n;

    // step 3: enter the required inputs
    printf("Enter the length of the reference string: ");//3.1 lenght of the reference string
    scanf("%d",&n);

    printf("Enter the reference string: ");//3.2 reference string
    for (i = 0; i < n; i++)
    {
        scanf("%d",&rs[i]);
    }

    printf("Enter the number of frames: ");//3.3 number of frames
    scanf("%d",&f);
    
    //step 4: set all frames as -1
    for (i = 0; i < f; i++)
    {
        m[i]=-1;
    }
    
    printf("Page Replacement process is: \n");
}*/