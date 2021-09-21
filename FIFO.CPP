#include<stdio.h>
#include<conio.h>
void main()
{
   int frame[10];
   int i,j,k,nframe,page[50],p;
   int flag,pfault=0,pos=0;
   printf("enter the no of frames");
   scanf("%d",&nframe);

   for(i=0;i<nframe;i++)
   {
      frame[i]=0;
   }
   printf("enter the no of pages");
   scanf("%d",&p);
   printf("enter the pages");
   for(i=0;i<p;i++)
  {
     scanf("%d",&page[i]);
  }
  for(i=0;i<p;i++)
  {
    flag=1;//page is available
    for(j=0;j<nframe;j++)
    {
       if(frame[j]==page[i])
       {
	flag=0;//page is not available
	break;
       }
    }
       if(flag==1)
       {
	 frame[pos]=page[i];
	 pos++;
	 pfault++;
	 if(pos>=nframe)
	 {
	    pos=0;
	 }
       }
       for(k=0;k<nframe;k++)
       {
	 printf("%d",frame[k]);
       }

 }
    printf("no of page faults is %d",pfault);
    getch();
}
