#include<stdio.h>
#define m 5
void get_value(int arr[])
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        j = i + 1;
        printf("\n Enter element %d: ", j);
        scanf("%d", &arr[i]);
    }
}
void print_value(int arr[], int n)
{
    int i;
    printf("{ ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}");
}
void function_sort(int arr[])
{
    int i, j, temp, swapping;

    for (i = 1; i < m; i++)
    {
        swapping = 0;
        for (j = 0; j < m-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapping = 1;
            }
        }
        if (swapping == 0)
        {
            break;
        }
    }
}

int find_intersection(int array1[], int array2[], int intersection_array[])
{
    int i = 0, j = 0, k = 0;
    while ((i < m) && (j < m))
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array1[i] > array2[j])
        {
            j++;
        }
        else
        {
            intersection_array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    return(k);
}

int find_union(int array1[], int array2[], int union_array[])
{
    int i = 0, j = 0, k = 0;
    while ((i < m) && (j < m))
    {
        if (array1[i] < array2[j])
        {
            union_array[k] = array1[i];
            i++;
            k++;
        }
        else if (array1[i] > array2[j])
        {
            union_array[k] = array2[j];
            j++;
            k++;
        }
        else
        {
            union_array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    if (i == m)
    {
        while (j < m)
        {
            union_array[k] = array2[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < m)
        {
            union_array[k] = array1[i];
            i++;
            k++;
        }
    }
    return(k);
}
void main()
{
    int array1[m],array2[m],intersection_array[m],union_array[m*2],num_elements;
    printf("Enter elements of array 1:\n");
    get_value(array1);

    printf("Elements of Array 1: \n");
    print_value(array1, m);


    function_sort(array1);
    printf("Sorted elements of Array 1: \n");
    print_value(array1, m);


    printf("Enter the elements of Array 2: \n");
    get_value(array2);
    printf("\n\n Elements of Array 2: \n");
    print_value(array2, m);


    function_sort(array2);
    printf("Sorted elements of Array 2: \n");
    print_value(array2, m);

    num_elements = find_intersection(array1, array2, intersection_array);
    printf("Intersection is: \n");
    print_value(intersection_array, num_elements);


    num_elements = find_union(array1, array2, union_array);
    printf(" Union is: \n");
    print_value(union_array, num_elements);
}







