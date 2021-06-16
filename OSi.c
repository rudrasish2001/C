/*#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


int SPLIT(int[],int,int);
void quick_sort(int*,int,int);

void merge_sort(int arr[],int low,int mid,int high)
{
    int i,j,k,l,b[20];
    l=low;
    i=low;
    j=mid+1;

    while((l<=mid)&&(j<=high))
    {
        if(arr[l]<=arr[j])
        {
            b[i]=arr[l];
            l++;
        }
        else
        {
            b[i]=arr[j];
            j++;
        }
        i++;
        if(l>mid)
        {
            for(k=j;k<=mid;k++)
            {
                b[i]=arr[k];
                i++;
            }
        }
        else
        {
            for(k=l;k<=mid;k++)
            {
                b[i]=arr[k];
                i++;
            }
        }
        for(k=low;k<=high;k++)
        {
            arr[k]=b[k];
        }
    }
}

void partition(int arr[],int low,int high)
{
    int mid;
    if(low<high)
    {
        double temp;
        mid=(low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        merge_sort(arr,low,mid,high);
    }
}

void display(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\t\t",a[i]);
    }
    printf("\n");
}

int main()
{
    int p_id,child_pid,size,i,status;
    printf("Enter the number of integers to be sorted \t");
    scanf("%d",&size);

    int a[size];
    int pArr[size];
    int cArr[size];

    for(i=0;i<size;i++)
    {
        printf("Enter number %d:",(i+1));
        scanf("%d",&a[i]);
        pArr[i]=a[i];
        cArr[i]=a[i];
    }

    printf("Your entered Integers for sorting\n");
    display(a,size);

    p_id=getpid();
    printf("Current process id is :%d\n",p_id);

    printf("[ Forking Child Process ... ] \n");
    child_pid=fork();

    if( child_pid < 0)
    {

        printf("\nChild Process Creation Failed!!!!\n");
        exit(-1);
    }
    else if( child_pid==0)
    {
        printf("\nThe Child Process\n");
        printf("\nchild process is %d",getpid());
        printf("\nparent of child process is %d",getpid());
        printf("Child is sorting the list of Integers by QUICK SORT::\n");
        quick_sort(cArr,0,size-1);
        printf("The sorted List by Child::\n");
        display(cArr,size);
        printf("Child Process Completed ...\n");
        sleep(10);
        printf("\nparent of child process is %d",getpid());
    }

    else
    {
        printf("parent process %d started\n",getpid());
        printf("Parent of parent is %d\n",getpid());
        sleep(30);
        printf("The Parent Process\n");
        printf("Parent %d is sorting the list of Integers by MERGE SORT\n",p_id);
        partition(pArr,0,size-1);
        printf("The sorted List by Parent::\n");
        display(pArr,size);
        wait(&status);
        printf("Parent Process Completed ...\n");
    }

    return 0;
}


int SPLIT(int a[],int lower,int upper)
{
    int i,p,q,t ;
    p=lower+1 ;
    q=upper ;
    i=a[lower] ;

    while(q>=p)
    {
        while(a[p]<i)
            p++;

        while(a[q]>i)
            q--;

        if(q>p)
        {
            t=a[p];
            a[p]=a[q];
            a[q]=t;
        }
    }

    t=a[lower];
    a[lower]=a[q];
    a[q]=t;

    return q;
}

void quick_sort(int a[],int lower,int upper)
{
    int i;
    if(upper>lower)
    {
        i=SPLIT(a,lower,upper);
        quick_sort(a,lower,i-1);
        quick_sort(a,i + 1,upper);
    }
}*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void quickSort(int [],int ,int );
int partition(int [],int ,int );

void mergeSort(int [],int ,int );
void merge(int [],int ,int ,int ,int );

int main()
{
 int i,j,n;
 int *status=NULL;
 int arr[30];

 printf("\nEnter the number of elements:");
 scanf("%d",&n);

 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 pid_t pid;
 pid=fork();

 if(pid==0)
 {
  printf("\n\t This is child process. ");
  printf("\n\t My process id is : %d", getpid());
  printf("\n\t My Parent process id is : %d", getppid());
  quickSort(arr,0,n-1);
  printf("\nQuicksort");
  for(i=0;i<n;i++)
   printf("    %d",arr[i]);
  printf("\n\n");
 }
 else
 {

  printf("\n\n\t Parent process resumed after the execution of child process with PID %d", pid);
  printf("\n\t My process id is : %d", getpid());
  printf("\n\t My Parent process id is : %d", getppid());
  mergeSort(arr,0,n-1);
  printf("\nMergesort:");
  for(i=0;i<n;i++)
   printf("    %d",arr[i]);
  printf("\n\n");
  pid=wait(status);

 }

}


void quickSort(int arr[],int low,int high)
{
 int j;
 if(low<high)
 {
  j=partition(arr,low,high);
  quickSort(arr,low,j-1);
  quickSort(arr,j+1,high);
 }
}

int partition(int arr[],int low,int high)
{
 int i,j,temp,pivot;
 pivot=arr[low];
 i=low;
 j=high+1;

 do
 {
  do
   i++;
  while(arr[i]<pivot && i<=high);
  do
   j--;
  while(arr[j]>pivot);

  if(i<j)
  {
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
  }
 }
 while(i<j);

 arr[low]=arr[j];
 arr[j]=pivot;

 return(j);
}

void mergeSort(int arr[],int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  mergeSort(arr,low,mid);
  mergeSort(arr,mid+1,high);
  merge(arr,low,mid,mid+1,high);
 }

}

void merge(int arr[],int i1,int j1,int i2,int j2)
{
 int temp[50];
 int i,j,k;
 i=i1;
 j=i2;
 k=0;

 while(i<=j1 && j<=j2)
 {
  if(arr[i]<arr[j])
   temp[k++]=arr[i++];
  else
   temp[k++]=arr[j++];
 }
 while(i<=j1)
  temp[k++]=arr[i++];
 while(j<=j2)
  temp[k++]=arr[j++];

 for(i=i1,j=0;i<=j2;i++,j++)
  arr[i]=temp[j];
}

