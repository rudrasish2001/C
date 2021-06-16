#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int arr[5] = { 1,2,3,4,5};

void* divide_half(void* arg) {
    int index = (uintptr_t)arg;
    int sum = 0,j;
    for (j = 0; j < 5; j++) {
        sum += arr[index + j];
    }
    printf("Local sum: %d\n", sum);
    sum = (uintptr_t)arg;
    return arg;
}
int array_sum(int arr[], int n)
{
    int sum = 0,i;   
    for (i = 0; i < n; i++)
    sum += arr[i];
 
    return sum;
}
 

int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    for (i = 0; i < 2; i++) {
        int* a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &divide_half, a) != 0) {
            perror("Failed to create thread");
        }
    }
    int sum1 = 0;
    for (i = 0; i < 2; i++) {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed thread");
        }
        sum1 += *r;
        free(r);
    }
    int arr[] = {12, 3, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("SUM : %d\n", sum1 + array_sum(arr, n));
    return 0;
}
