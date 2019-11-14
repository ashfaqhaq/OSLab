#include<stdio.h>
void main()
{
  int n,f,frames[5]={-1,-1,-1,-1,-1},timecounter=0,time[5],pagefaults=0,i,j,k,limit=0;
  printf("Enter the number of frames\n");
  scanf("%d",&f);
  printf("Enter the length of the reference string\n");
  scanf("%d",&n);
  printf("Enter the reference string\n");
  for(i=0;i<n;i++)
  {
     int req,flag=0;
     scanf("%d",&req);
     timecounter++;
     //searching whether the page is present in the frame or not
     for(j=0;j<limit;j++)
     {
       if(frames[j]==req)
       {
         flag=1;
         break;
       }
     }
     //if the frame is not found
     if(flag==0)
     {
       pagefaults++;
       if(limit<f)
       {
         frames[limit]=req;
         time[limit++]=timecounter;
       }
       else
       {
          int min=time[0],minindex=0;
          //finding the page which was least recently used
          for(j=1;j<f;j++)
          {
             if(time[j]<min)
             {
                min=time[j];
                minindex=j;
             }
          }
          
          frames[minindex]=req;
          time[minindex]=timecounter;
       }
     }
     //if no page fault then just update the time of the referenced string
     else
     {
       for(j=0;j<f;j++)
       {
          if(frames[j]==req)
          {
            time[j]=timecounter;
          }
       }
     }
     
     for(j=0;j<f;j++)
       printf("%d ",frames[j]);
     printf("\n");
   }
   printf("the number of page faults is %d\n",pagefaults);
}

     
          
          
          
          
          
          
          
          
 
