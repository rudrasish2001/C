#include<stdio.h>
#include<pthread.h>
void *func(void *p)
{
printf("tid ID--->%d\n",getpid());
}
int main()
{
pthread_t tid;
pthread_create(&tid,NULL,func,NULL);
printf("Parent ID is ---> %d\n",getpid());
pthread_join(tid,NULL);
printf("No more thread id!\n");
}
