#include <stdio.h>
#include <conio.h>
void main()
{
    int n = 6, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt = 0, avg_tat = 0;
    FILE *fptr;

    fptr = fopen("input.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(0);
    }
    for (i = 0; i < 5; i++)
    {
        fscanf(fptr, "%d,", &bt[i]);
    }
    fclose(fptr);

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    printf("Enter Quantum time");
    scanf("%d", &qt);
    while (1)
    {
        for (i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }
            if (rem_bt[i] > qt)
                rem_bt[i] = rem_bt[i] - qt;
            else if (rem_bt[i] >= 0)
            {
                temp = rem_bt[i];
                rem_bt[i] = 0;
            }
            sq = sq + temp;
            tat[i] = sq;
        }
        if (n == count)
            break;
    }
    fptr = fopen("output.txt", "w");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "\nprocess\t\tBurst Time\t\tTurn Around Time\t\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        avg_tat = avg_tat + tat[i];
        fprintf(fptr, "\n%d\t%d\t\t%d\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    avg_tat = avg_tat / n;
    fprintf(fptr, "Average waiting time = %f\n", awt);
    fprintf(fptr, "Average turnaround_time = %f\n", avg_tat);
    fclose(fptr);
    getch();
}
