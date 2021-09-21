#include<stdio.h>
#include<conio.h>

void main()
{
   clrscr();
   int i,j,min,temp,n,p[100],bursttime[100],arrivaltime[100],waitingtime[100],turnaroundtime[100],avgturnaroundtime=0,avgwaitingtime=0;
   printf("enter the no of processes");
   scanf("%d",&n);

   printf("enter the arrival time of procceses\n");
   for(i=0;i<n;i++)
   {
      printf("P[%d] ==> ",i+1);
      scanf("%d",&arrivaltime[i]);
   }

   printf("enter the burst time of proceeses\n");
   for(i=0;i<n;i++)
   {
      printf("P[%d] ==> ",i+1);
      scanf("%d",&bursttime[i]);
      p[i]=i+1;
   }

   for(i=0;i<n;i++)
   {
      min = i;
      for(j=i+1;j<n;j++)
      {
	  if(bursttime[j]<bursttime[min]);
	  {
	     min=j;
	  }
       temp=bursttime[i];
       bursttime[i]=bursttime[min];
       bursttime[min]=temp;

       temp=p[i];
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

      printf("Proccesses  ARRIVAL TIME  BURST TIME  WAITING TIME  TURNAROUND TIME \n");
  for(i=0; i<n;i++)
  {
      turnaroundtime[i]=waitingtime[i]+bursttime[i];
      avgwaitingtime+=waitingtime[i];
      avgturnaroundtime+=turnaroundtime[i];
      printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,arrivaltime[i],bursttime[i],waitingtime[i],turnaroundtime[i]);
  }

  avgwaitingtime /=i;
  avgturnaroundtime /=i;
  printf("the average waiting time is: %d\n",avgwaitingtime);
  printf("the average turnaround time is: %d",avgturnaroundtime);
  getch();

}
}