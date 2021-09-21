#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define max 25
void *customer(void *num);
void *barber(void *);

sem_t waitingroom;
sem_t barberchair;
sem_t barberpillow;
sem_t seatbelt;
int alldone=0;

int main(int argc,char* argv[])
{
	pthread_t btid;
	pthread_t tid[max];
	int x,y,i;
	int num[max];
	printf("\n max customers are only 25 \n enter number of customers and chairs.....\t ");
	scanf("%d",&x);
	printf("\n enter number of chairs...");
	scanf("%d",&y);
	if(x>max)
	{
		printf("\n maximum number of customers %d",max);
		system("PAUSE");
		return 0;
	}
	printf("\n solution for the solving philosophers problem");
	for(i=0;i<max;i++)
	{
		num[i]=i;
	}
	sem_init(&waitingroom,0,y);
	sem_init(&barberchair,0,1);
	sem_init(&barberpillow,0,0);
	sem_init(&seatbelt,0,0);
	
	pthread_create(&btid,NULL,barber,NULL);
	for(i=0;i<x;i++)
	{
		pthread_create(&tid[i],NULL,customer,(void *)&num[i]);
	}
	for(i=0;i<x;i++)
	{
		pthread_join(tid[i],NULL);
		sleep(1);
	}
	alldone=1;
	sem_post(&barberpillow);
	pthread_join(btid,NULL);
	system("PAUSE");
	return 0;
}
void *customer(void *number)
{
	int n=*(int*)number;
	printf("\n customer %d leaving for barbershoop",n);
	sleep(2);
	printf("\n customer %d arrived at barber shop",n);
	sem_wait(&waitingroom);
	printf("\n customer %d entering into room",n);
	sem_wait(&barberchair);
	sem_post(&waitingroom);
	printf("customer %d waking up the barber...");
	sem_post(&barberpillow);
	sem_wait(&seatbelt);
	sem_post(&barberchair);
	printf("\n customer %d leaving the barbershop",n);
}
void *barber(void *junk)
{

	while(!alldone)
	{
		printf("\n the barber is sleeping...");
		sem_wait(&barberpillow);
		if(!alldone)
		{
			printf("\n the barber is cutting hair...");
			sleep(3);
			printf("\n the barber has finished hair cutting");
		}
		else
		{
			printf("the barber is going home for today...");
		}
		
	}
}
