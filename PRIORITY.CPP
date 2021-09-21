#include<stdio.h>
#include<conio.h>

void main()
{
   clrscr();
   int i,j,n,temp,min,p[100],arrivaltime[100],bursttime[100],priority[100],turnaroundtime[100],waitingtime[100],avgturnaroundtime=0,avgwaitingtime=0,run;
   printf("enter the value of processes");
   scanf("%d",&n);

   printf("enter the arrival time of the processes");
   for(i=0;i<n;i++)
   {
      printf("p[%d]==> ",i+1);
      scanf("%d",&arrivaltime[i]);
   }

   printf("enter the burst time and priorities ");
    for(i=0;i<n;i++)
    {
       printf("p[%d]==> ",i+1);
       printf("enter burst time :");
       scanf("%d",&bursttime[i]);
       printf("PRIORITY ==> ");
       scanf("%d",&priority[i]);
       p[i]=i+1;
   }

   for(i=0;i<n;i++)
   {
      min=i;
      for(j=i+1;j<n;j++)
      {
	 if(priority[j]<priority[min])
	 {
	    min=j;
	 }
      }
      temp = priority[i];
      priority[i]=priority[min];
      priority[min]=temp;

      temp = bursttime[i];
      bursttime[i]=bursttime[min];
      bursttime[min]=temp;

      temp = p[i];
      p[i]=p[min];
      p[min]=temp;
 }
 waitingtime[0]=0;
      for(i=1;i<n;i++)
      {
	 waitingtime[i]=0;
	 for(j=0;j<n;j++)
	 {
	     waitingtime[i]+=bursttime[i];
	 }
      }

      printf("Pro     AT     BT       P      WT      TAT \n");
  for(i=0; i<n;i++)
  {
      turnaroundtime[i]=waitingtime[i]+bursttime[i];
      avgwaitingtime+=waitingtime[i];
      avgturnaroundtime+=turnaroundtime[i];
      printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",i+1,arrivaltime[i],bursttime[i],priority[i],waitingtime[i],turnaroundtime[i]);
  }

  avgwaitingtime /=n;
  avgturnaroundtime /=n;
  printf("the average waiting time is: %d\n",avgwaitingtime);
  printf("the average turnaround time is: %d",avgturnaroundtime);
  getch();

}


