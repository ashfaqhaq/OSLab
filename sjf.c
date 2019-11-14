#include<stdio.h>
int bt[10],ct[10],tat[10],wt[10],bttemp[10];
int main()
{
  int n,i;
  printf("Please enter number of process\n");
  scanf("%d",&n);
  printf("Assuming that all process arrive at time t=0\n");
  printf("Enter the burst times of the process\n");
  for(i=0;i<n;i++) 
  {
    scanf("%d",&bt[i]);
    bttemp[i]=bt[i];
  }
  int time=0,index,min=bt[0];
  for(i=0;i<n;i++)
  {
    //repeat for each process
    //setting the burst time of the completed process to 0
    for(int j=0;j<n;j++)
    {
      if(bt[j]!=0){
        min=bt[j];
        break;}
     }
    for(int j=0;j<n;j++)
    {
      if((bt[j]<=min) && (bt[j]!=0))
      {
         min=bt[j];
         index=j;
      }
    }
    time+=bt[index];
    bt[index]=0;
    ct[index]=time;
   }
   int avgtat,sum=0,sumwt=0,avgwt;
   for(i=0;i<n;i++)
   {
     tat[i]=ct[i];
     sum+=tat[i];
     wt[i]=tat[i]-bttemp[i];
     sumwt+=wt[i];
   }
   avgwt=sumwt/n;
   avgtat=sum/n;
   printf("The average turn around time using sjf scheduling algorithm is : %d\n",avgtat);
   printf("The average waiting time using sjf scheduling algorithm is : %d\n",avgwt);
}

     
