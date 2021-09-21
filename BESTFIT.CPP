#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,nb,np,temp,lowest=10000;
 int frag[10],block[10],process[10];
 static int blockarr[10],processarr[10];
 printf("Enter no of blocks");
 scanf("%d",&nb);
 printf("Enter no of process");
 scanf("%d",&np);
 printf("Enter size of block");
 for(i=1;i<=nb;i++)
 {
    scanf("%d",&block[i]);
 }
 printf("Enter size of process");
 for(i=1;i<=np;i++)
 {
    scanf("%d",&process[i]);
 }
 for(i=1;i<=np;i++)
 {
   for(j=1;j<=nb;j++)
   {
      if(blockarr[j]!=1)
      {
	temp=block[j]-process[i];
	if(temp>=0)
	if(lowest>temp)
	{

	  processarr[i]=j;
	  lowest=temp;
	}
      }
    }
    blockarr[processarr[i]]=1;
    frag[i]=lowest;
    lowest=10000;
  }
  printf("\nProcess  number\tBlock number\t processsize\tblocksize\tfragement");
  for(i=1;i<=np;i++)
  {
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,processarr[i],process[i],block[processarr[i]],frag[i]);
  }
  printf("\n");
  getch();
 }
