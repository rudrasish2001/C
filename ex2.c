#include<pthread.h> 
#include<stdio.h> 
int sum;  
void *func(void *param); 
int main(int argc, char *argv[]) 
{ 
pthread_t tid; 
pthread_attr_t attr; 
if(argc != 2) 
{ 
fprintf(stderr, "usage: a.out <integer value>\n");  
}
if(atoi(argv[1]) < 0) 
{ 
fprintf(stderr, "%d must be >= 0 \n", atoi(argv[1])); 
}
pthread_attr_init(&attr);
Program pthread_create(&tid, &attr, func, argv[1]); 
pthread_join(tid, NULL); printf("sum = %d\n", sum); 
}
void *func(void *param) 
{ 
int upper = atoi(param); 
int i; 
sum=0; 
if(upper > 0) 
{ 
for(i=1; i <= upper; i++) 
sum += i; 
}
pthread_exit(0); 
}
