#include<stdio.h>
main()
{
	int a[100],b[99],m,n,i;
	for(i=0;i<100;i++)
	{
		a[i]=-1;
	}
	int *p;
	printf("\n enter the starting address");
	scanf("%d",&n);
	printf("\n enter the no.of nodes");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("\n enter the index %d",(i+1));
		scanf("%d",&b[i]);
	}
	p=&b[0];
	a[n]=1;
	printf("\n file1 starting address is %d \n your index location",n);
	for(i=0;i<n;i++)
	{
		if(a[b[i]]==-1)
		{
			a[b[i]]=1;
			printf("\n%d",*p);
			p++;
		}
		else
		{
			printf("same block already allocated %d \n",b[i]);
		}
	}
}
