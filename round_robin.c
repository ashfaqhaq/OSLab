#include<stdio.h>
void main()
{
int n,i,q,x=0,count=0,temp;
int bt[10],temp_bt[10],tat[10],wt[10];
float twt=0,ttat=0;
printf("\nEnter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
   printf("Enter the burst time of process %d : ",i);
   scanf("%d",&bt[i]);
   temp_bt[i]=bt[i];
}
printf("\nEnter the time quantum : ");
scanf("%d",&q);
while(1)
{
   for(i=0;i<n;i++)
   {
   	temp=q;
	if(temp_bt[i]==0)
	{
	  count++;
	  continue;
	}
	if(temp_bt[i]>q)
	  temp_bt[i]=temp_bt[i]-q;
	else if(temp_bt[i]>=0)
	{
	  temp=temp_bt[i];
	  temp_bt[i]=0;
	}
	x=x+temp;
	tat[i]=x;
   }
   if(n==count)
     break;
}

for(i=0;i<n;i++)
{
   wt[i]=tat[i]-bt[i];
   twt=twt+wt[i];
   ttat=ttat+tat[i];
}
printf("\nProcess\t|Burst Time\t|Wait Time\t|Turn-Around Time");
for(i=0;i<n;i++)
{
   printf("\n%d\t|%d\t\t|%d\t\t|%d",i,bt[i],wt[i],tat[i]);
}
printf("\nAverage waiting time is %f",twt/n);
printf("\nAverage turn around time is %f\n\n",ttat/n);
}
