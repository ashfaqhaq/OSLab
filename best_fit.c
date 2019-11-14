
/*
     |\  |   (^)   |\  |
     | \ |  (   )  | \ |  SENSE
     |  \|   (^)   |  \|
                                     */
                                     
//instead of sorting try to find the minimum page left in each iteration

#include<stdio.h>
int main()
{
  int  n,b,i,j;
  printf("Please enter the number of process\n");
  scanf("%d",&n);
  printf("Please enter the number of blocks\n");
  scanf("%d",&b);
  int processSize[10],blockSize[10],flag[10]={0},status[10],order[10];
  printf("Please enter the size of process\n");
  for(i=0;i<n;i++)
    scanf("%d",&processSize[10]);
  printf("Please enter the size of blocks\n");
  for(i=0;i<b;i++)
    scanf("%d",&blockSize[10]);
  for(i=0;i<b;i++)
    order[i]=i;
  //sorting the blocks in ascending order
  for(i=0;i<b;i++)
  {
    for(j=0;j<b-i;j++)
    {
      if(blockSize[j]>blockSize[j+1])
      {
         int temp=order[j];
         order[j]=order[j+1];
         order[j+1]=temp;
      }
    }
  }
  for(i=0;i<b;i++)
    printf("%d\n",order[i]);
  int currblock;
  for(i=0;i<n;i++)
  {
    for(j=0;j<b;j++)
    {
      currblock=order[j];
      if(flag[currblock]==0)
      {
        if(blockSize[currblock]>=processSize[i])
        {
          status[currblock]=i;
          flag[currblock]=1;
          break;
        }
      }
    }
  }
  /*printf("The final status of the memory blocks using best fit is\n");
  for(i=0;i<b;i++)
  {
    if(flag[i]==0)
      printf("Block[%d] -> free\n",i);
    else
      printf("Block[%d] -> process[%d]\n",i,status[i]);
   }*/
 }
 
      
