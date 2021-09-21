#include<stdio.h>
main()
{
	static int flag[10],alloc[10];
	int b[10],p[10],nb,np,i,j,c[10],temp,low=9999;
	printf("enter number of blocks \t");
	scanf("%d",&nb);
	printf("\n enter number of processes \t");
	scanf("%d",&np);
	printf("\n enter block size of each block");
	for(i=1;i<=nb;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\n enter procesess size of each processess");
	for(i=1;i<=np;i++)
	{
		scanf("%d",&p[i]);
	}
	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(flag[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
				{
					if(low>temp)
					{
						alloc[i]=j;
						low=temp;
					}
				}
			}
		}
		flag[alloc[i]]=1;
		low=10000;
		
	}
	printf("\n prono\tprocesessize\tblockno\tblocksize \n");
	for(i=1;i<=nb;i++)
	{
		if(alloc[i]!=0)
		{
			printf("%d\t\t%d\t\t%d\t\t%d\t",i,p[i],alloc[i],b[alloc[i]]);
		}
		else
		{
			printf("not allocated");
		}
		printf("\n");
	}
}
