#include<stdio.h>
#define max 25
main()
{
	int page[max],i,n,ps,fs,off,pno;
	int choice=0;
	printf("\n enter number of pages in memory...");
	scanf("%d",&n);
	printf("\n enter the pagesize....");
	scanf("%d",&ps);
	printf("\n enter the framesize...");
	scanf("%d",&fs);
	for(i=0;i<n;i++)
	{
		page[i]=-1;
	}
	printf("\n enter the page table...");
	printf("\n enter the frameno as -1 if that page is not there in any frame...");
	printf("\n pageno \t frameno\t");
	for(i=0;i<n;i++)
	{
		printf("\n \n %d\t",i);
		scanf("%d",&page[i]);
	}
	do
	{
		printf("\n enter the logicall address ie pgno,offset");
		scanf("%d%d",&pno,&off);
		if(page[pno]==-1)
		{
			printf("\n the required page is not availabele in any frames");
		}
		else
		{
			printf("\n physical address ie frameno,offset %d %d",page[pno],off);
		}
		printf("\n do you want to continue (1/0) ?:");
		scanf("%d",&choice);
	}while(choice==1);

}
