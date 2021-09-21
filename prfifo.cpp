#include<stdio.h>
main()
{
	int s,i,j,m,n,a[20],pf=0,b[20];
	printf("how many number of pages you are entering....");
	scanf("%d",&n);
	printf("\n enter pages ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf(" \n enter number of frames");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		b[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				s++;
				pf--;
			}
		}
		pf++;
		if(pf<=m && s==0)
		{
			b[i]=a[i];
		}
		else if(s==0)
		{
			b[(pf-1)%m]=a[i];
		}
		printf("\n");
		for(j=0;j<m;j++)
		{
			printf("%d \t",b[j]);
		}
	}
}
