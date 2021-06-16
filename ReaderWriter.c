#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int count=0;

void *reader(void* parameter)
{
    sem_wait(&x);
    count++;
    if(count==1)
        sem_wait(&y);
    sem_post(&x);
    printf("% Reader is inside\n",count);
    usleep(3);
    sem_wait(&x);
    count--;
    if(count==0)
        sem_post(&y);
    sem_post(&x);
    printf("Reader is leaving\n",count+1);
    return NULL;
}

void *writer(void* parameter)
{
    printf("Writer is trying to enter\n");
    sem_wait(&y);
    printf("Writer has entered\n");
    sem_post(&y);
    printf("Writer is leaving\n");
    return NULL;
}
int main()
{
    int n1,i;
    printf("Enter the number of readers:");
    scanf("%d",&n1);
    printf("\n");
    int n2[n1];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    for(i=0;i<n1;i++)
    {
        pthread_create(&writerthreads[i],NULL,reader,NULL);
        pthread_create(&writerthreads[i],NULL,reader,NULL);
    }
    for(i=0;i<n1;i++)
    {
        pthread_join(&writerthreads[i],NULL);
        pthread_join(&writerthreads[i],NULL);
    }
}
