#include<stdio.h>
main()
{
int n,i,bt[10],st[10],wt[10],s1=0,t,ta[10],qua,a,w[10];
printf("enter the number of processes");
scanf("%d",&n);
printf("enter the burst time");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
st[i]=bt[i];
}
printf("enter the weights in the range of 1-5");
for(i=0;i<n;i++)
{
scanf("%d",&wt[i]);
}
for(i=0;i<n;i++)
{
s1=s1+wt[i];
}
t=0;
qua=s1/n;
printf("quantu is %d",qua);
while(1)
{
a=1;
wt[0]=0;
for(i=0;i<n;i++)
{
if(st[i]>0)
{
a=0;
if(st[i]>qua)
{
t=t+qua;
st[i]=st[i]-qua;
}
else
{
t=t+st[i];
wt[i]=t-bt[i];
st[i]=0;
}
}
}
if(a==1)
{
break;
}
}
}

