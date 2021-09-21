#include<stdio.h>
#include<conio.h>
void main()
{

   int n,run,bursttime[100],arrivaltime[100],waitingtime[100],turnaroundtime[100],avgturnaroundtime=0,avgwaitingtime=0,i,j;
   do
   {
   clrscr();
   printf("Enter the total number of processes ==> ");
   scanf("%d",&n);
   printf("Enter the arrival time for processes\n");
   for(i=0;i<n;i++)
   {
      printf("p[%d] ==> ",i+1);
      scanf("%d",&arrivaltime[i]);
   }


   printf("Enter the burst time of the proccesses\n");
   for(i=0;i<n;i++)
   {
     printf("P[%d] ==>\n",i+1);
     scanf("%d",&bursttime[i]);
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

  avgwaitingtime /=n;
  avgturnaroundtime /=n;
  printf("the average waiting time is: %d\n",avgwaitingtime);
  printf("the average turnaround time is: %d\n",avgturnaroundtime);
  getch();
  printf("enter value of run==>");
  scanf("%d",&run);

  }while(run==1);

}



