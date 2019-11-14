#include<stdio.h>
int main()
{
  int n,b,i,j;
  printf("Please enter the number of process (max=10)\n");
  scanf("%d",&n);
  printf("Please enter the number of blocks available in the memory (max=10)\n");
  scanf("%d",&b);
  int blockSize[20],processSize[20],flag[20]={0},status[20];
  printf("Please enter the size of each process\n");
  for(i=0;i<n;i++)
    scanf("%d",&processSize[i]);
  printf("Please enter the size of each block available in the memory\n");
  for(i=0;i<n;i++)
    scanf("%d",&blockSize[i]);
  for(i=0;i<n;i++)
  {
    //process in question here is the process[i]
    for(j=0;j<b;j++)
    {
      if(flag[j]!=1)
      {
        if(blockSize[j]>=processSize[i])
        {
          status[j]=i+1;
          flag[j]=1;
          break;
        }
      }
    }
  }
  printf("The status of memory after allocation of all the blocks is \n");
  for(i=0;i<b;i++)
  {
     if(flag[i]==0)
       printf("Block[%d] -> free\n",i);
     else
       printf("Block[%d] -> Process[%d]\n",i,status[i]);
   }
}
  
    
    
