#include<stdio.h>
main()
{
	int r,n,i,j,k,ind=0,f[20],max[10][10],alloc[10][10],ava[3];
	printf("enter number of processes...");
	scanf("%d",&n);
	printf("enter number of resources...");
	scanf("%d",&r);
	printf("enter allocated resources of each processes...");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter maximum resources of each processes...");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	int a;
	printf("enter available or work arry size...");
	scanf("%d",&a);
	printf("enter the available array ele....");
	for(i=0;i<a;i++)
	{
		scanf("%d",&ava[i]);
	}
	int safe[10],need[10][10];
	for(k=0;k<n;k++)
	{
		f[k]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	int y,flag;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				flag=0;
				for(j=0;j<r;j++)
				{
					if(need[i][j]>ava[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					safe[ind++]=i;
					for(y=0;y<r;y++)
					{
						ava[y]+=alloc[i][y];
					}
					f[i]=1;
				}
			}
		}
	}
	printf("the safe sequence is...\n");
	for(i=0;i<n;i++)
	{
		printf("p%d->",safe[i]);
	}
}
