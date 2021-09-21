#include<stdio.h>
#include<stdlib.h>
struct filestr
{
	char name[20];
	int stblk;
	int len;
}file[20];
int i,j,disk[512];
int n;
main()
{
	for(j=0;j<512;j++)
	{
		disk[j]=0;
	}
	int x,y,flag=0;
	printf("\n enter no.of files");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter the name..");
		scanf("%s",&file[i].name);
		printf("\n enter the starting block");
		scanf("%d",&file[i].stblk);
		printf("\n enter the len ");
		scanf("%d",&file[i].len);
		x=file[i].stblk;
		y=file[i].len;
		for(j=x;j<(x+y);j++)
		{
			if(disk[j]==1)
			{
				printf("\n sequential allocation is not possible...");
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(j=x;j<(x+y);j++)
			{
				disk[j]=1;
			}
			printf("\n allocation is done sequentially...");
		}
	}
}
