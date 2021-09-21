#include<stdio.h>
main()
{
	int n,i,nohung,hung[10],status[10];
	printf("\n enter number of philosophers...");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		status[i]=1;
	}
	printf("how many are hungry....");
	scanf("%d",&nohung);
	if(nohung==n)
	{
		printf("deadlock situation occurs...");
	}
	else
	{
		for(i=0;i<nohung;i++)
		{
			printf("philosopher position %d",(i+1));
			scanf("%d",&hung[i]);
			status[hung[i]]=2;
		}
	}
	printf("\n allowing one philosopher at a time....");
	for(i=0;i<nohung;i++)
	{
		printf("\n philosopher %d is ready to eat",hung[i]);
		status[hung[i]]=1;
		for(int x=0;x<nohung;x++)
		{
			if(status[hung[x]]==2)
			{
				printf("\n philosopher %d is waiting...",hung[x]);
			}
		}
	}
}
