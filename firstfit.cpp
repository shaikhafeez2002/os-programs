#include<stdio.h>
main()
{
	int flag[10],alloc[10],b[10],p[10],nb,np,i,j;
	for(i=0;i<10;i++)
	{
		flag[i]=0;
		alloc[i]=-1;
	}
	printf("enter number of blocks \t");
	scanf("%d",&nb);
	printf("\n enter number of processes \t");
	scanf("%d",&np);
	printf("\n enter block size of each block");
	for(i=0;i<nb;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\n enter procesess size of each processess");
	for(i=0;i<np;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(flag[j]==0 && b[j]>=p[i])
			{
				alloc[j]=i;
				flag[j]=1;
				break;
			}
		}
	}
	printf("\n blockno\tblocksize\tprocessno\tprocessessize \n");
	for(i=0;i<nb;i++)
	{
		printf(" %d  \t %d  \t",i+1,b[i]);
		if(flag[i]==1)
		{
			printf("  %d  \t  %d",alloc[i]+1,p[alloc[i]]);
		}
		else
		{
			printf("not allocated");
		}
		printf("\n");
	}
}
