#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

struct dirent*dir;

int main(void)
{
	DIR *d;
	d=opendir(".");
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			printf("%s\n",dir->d_name);
		}
		closedir(d);
	}
	return 0;
}
