#include<stdio.h>
#include<unistd.h>
#define SIZE 16
char* msg1="Hello World!#1";
char* msg2="Hello World!#2";
char* msg3="Hello World!#3";

int main()
{
 char inbuf[SIZE];
 int p[2],pid,nbytes;
 if(pipe(p)<0)
 {
  exit(1);
 }
 if((pid=fork())>0)
 {
  write(p[1],msg1,SIZE);
  write(p[1],msg2,SIZE);
  write(p[1],msg3,SIZE);
  wait(NULL);
 }
 else
 {
 while((nbytes=read(p[0],inbuf,SIZE))>0)
 {
  printf("%s\n",inbuf);
 }
 if(nbytes!=0)
 {
  exit(2);
 }
 printf("Finished reading\n");
 }
 return 0;
 }
