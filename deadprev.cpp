#include<stdio.h>
main()
{
	int alloc[10][10],max[10][10],need[10][10],n,r,ava[10],tres[10],work[10],flag[10];
	int i,j,total,count=0,p,t;
	printf("enter number of processes....");
	scanf("%d",&n);
	printf("enter number of resources...");
	scanf("%d",&r);
	printf("\n enter total number of each resources...");
	for(i=1;i<=r;i++)
	{
	    scanf("%d",&tres[i]);
	    
	}
	printf("enter max resources of each processes..");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\n enter the allocated resources of each processes..");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\n available resources...");
	for(j=1;j<=r;j++)
	{
		ava[j]=0;
		total=0;
		for(i=1;i<=n;i++)
		{
			total+=alloc[i][j];
		}
		ava[j]=tres[j]-total;
		work[j]=ava[j];
		printf("\n %d \t",work[j]);
	}
	for(i=1;i<=n;i++)
	{
		flag[i]=0;
	}
	do
	{
		for(i=1;i<n;i++)
		{
			for(j=1;j<=r;j++)
			{
			    need[i][j]=max[i][j]-alloc[i][j];	
			}
		
		}
		printf("allocated matrix....max....need");
		for(i=1;i<=n;i++)
		{
			printf("\n");
			for(j=1;j<=r;j++)
			{
				printf("%d",alloc[i][j]);
			}
			printf("|");
		
			for(j=1;j<=r;j++)
			{
				printf("%d",max[i][j]);
			}
			printf("|");
		
			for(j=1;j<=r;j++)
			{
				printf("%d",need[i][j]);
			}
		
			
		}
		p=0;
		for(i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
				p=i;
				for(j=1;j<=r;j++)
				{
					if(work[j]<need[i][j])
					{
						p=0;
						break;
					}
				}
			}
			if(p!=0)
			{
				break;
			}
		}
		if(p!=0)
		{
			printf("process completed is %d",i);
			count++;
			printf("available matrix is....");
			for(j=1;j<=r;j++)
			{
				work[j]+=alloc[p][j];
				alloc[p][j]=0;
				max[p][j]=0;
				flag[p]=1;
				printf("%d",work[j]);
				
			}
		}
	}while(count!=n && p!=0);
	if(count==n)
	{
		printf("\n the system is safe system...");
		
	}
	else
	{
		printf("\n the system is not safe system....");
	}
}
