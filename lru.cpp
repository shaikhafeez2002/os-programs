#include<stdio.h>
int findlru(int time[],int n)
{
	int i,min,pos=0;
	min=time[0];
	for(i=1;i<n;i++)
	{
		if(min>time[i])
		{
			min=time[i];
			pos=i;
		}
	}
	return pos;
}
main()
{
	int n,f,a[10],b[10],pf=0,time[10],count=0,pos,flag1,flag2,i,j;
	printf("\n enter number of pages...");
	scanf("%d",&n);
	printf("\n enter number of frames...");
	scanf("%d",&f);
	printf("\n enter pages...");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		b[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		flag1=0,flag2=0;
		for(j=0;j<f;j++)
		{
			if(a[i]==b[j])
			{
				count++;
				time[j]=count;
				flag2=1;
				flag1=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<f;j++)
			{
				if(b[j]==-1)
				{
					count++;
					pf++;
					time[j]=count;
					b[j]=a[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			pos=findlru(time,f);
			count++;
			pf++;
			b[pos]=a[i];
			time[pos]=count;
		}
		printf("\n");
	for(j=0;j<f;j++)
	{
		printf("%d \t",b[j]);
	}
	}
}
