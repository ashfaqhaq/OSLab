#include<stdio.h>
int at[10],bt[10],ct[10],tat[10],wt[10];
int main()
{
  int n,i;
  printf("Please enter number of process\n");
  scanf("%d",&n);
  printf("Enter the arrival times of the processes\n");
  for(i=0;i<n;i++)
    scanf("%d",&at[i]);
  printf("Please enter the burst times of the processes\n");
  for(i=0;i<n;i++)
    scanf("%d",&bt[i]);
  printf("******FCFS********\n");
  int time=0;
  for(i=0;i<n;i++)
  {
     time+=bt[i];
     ct[i]=time;
     tat[i]=ct[i]-at[i];
  }
  printf("The average turn around time is :");
  float avgtat;
  int sum=0;
  for(i=0;i<n;i++)
    sum+=tat[i];
  avgtat=sum/n;
  printf("%f\n",avgtat);
  sum=0;
  for(i=0;i<n;i++)
  { 
    wt[i]=tat[i]-bt[i];
    sum+=wt[i];
  }
  float avgwt;
  avgwt=sum/n;
  printf("The average waiting time is : %f\n",avgwt);
}
