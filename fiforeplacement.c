#include<stdio.h>
void main()
{
  int f,n,queue[5]={-1,-1,-1,-1,-1},rear=0,i,pagefaults=0,pagehits=0;
  printf("Please enter the number of frames\n");
  scanf("%d",&f);
  printf("Please enter the number of requests\n");
  scanf("%d",&n);
  printf("Please enter the sequence of requests\n");
  for(i=0;i<n;i++)
  {
    int req,j,k,flag=0;
    scanf("%d",&req);
    //search for the element in the queue
    for(j=0;j<rear;j++)
    {
      if(req==queue[j])
      {
        flag=1;
        break;
      }
    }
//    printf("The falg value is %d\n",flag);
    if(flag==0)
    {
       pagefaults++;
       if(rear<f)
       {
         queue[rear]=req;
         rear++;
       }
       else
       {
         //shift all the elements towards left and insert the new page in the end
         for(k=0;k<f-1;k++)
           queue[k]=queue[k+1];
         queue[k]=req;
       }
     }
     else
       pagehits++;
     for(k=0;k<f;k++)
     {
       printf("%d ",queue[k]);
     }
     printf("\n");
   }
   printf("The number of page faults for the given input string is: %d\n",pagefaults);
   printf("The final status of the memory is\n");
   for(i=0;i<f;i++)
   {
     printf("%d ",queue[i]);
   }
  
}
 
     
        
       
        
  
