#include<stdio.h>
main()
{
	int n,f,a[10],b[10],temp[10],pos,i,j,k,flag1,flag2,flag3,flag4,pf=0,max;
	printf("enter number of pages...");
	scanf("%d",&n);
	printf("\n enter number of frames....");
	scanf("%d",&f);
	printf("\n enter the pages...");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<f;i++)
	{
		b[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		flag1=0;
		flag2=0;
		for(j=0;j<f;j++)
		{
			if(b[j]==a[i])
			{
				flag1=1;
				flag2=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<f;j++)
			{
				if(b[j]==-1)
				{
					b[j]=a[i];
					flag2=1;
					pf++;
					break;
				}
			}
		}
		if(flag2==0)
		{
			flag3=0;
			for(j=0;j<f;j++)
			{
				temp[j]=-1;
				for(k=i+1;k<n;k++)
				{
					if(b[j]==a[k])
					{
						temp[j]=k;
						break;
						
					}
				}
			}
		
		for(j=0;j<f;j++)
		{
			if(temp[j]==-1)
			{
				pos=j;
				flag3=1;
				break;
			}
		}
		if(flag3==0)
		{
			max=temp[0];
			pos=0;
			for(j=0;j<f;j++)
			{
				if(temp[j]>max)
				{
					max=temp[j];
					pos=j;
					
				}
			}
		}
		b[pos]=a[i];
		pf++;
	}
	printf("\n");
	for(j=0;j<f;j++)
	{
		printf("%d \t",b[j]);
	}
	}
}
