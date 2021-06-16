#include<stdio.h>
#include<stdlib.h>


{

    FILE *fp=fopen("C:\\Users\\KIIT\\Desktop\\abc.txt","r");
    if(fp == NULL)
	{
        printf("File not found!");
        exit(0);
    }
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
    float average_wait_time, average_turnaround_time;

    fscanf(fp,"%d", &limit);
    printf("\nEnter Total Number of Processes:%d\t",limit);
    x = limit;
    for(i = 0; i < limit; i++)
    {
        printf("\nEnter Details of Process[%d]\n", i + 1);

        fscanf(fp,"%d", &arrival_time[i]);
        printf("Arrival Time:%d  \t",arrival_time[i]);

        fscanf(fp,"%d", &burst_time[i]);
        printf("  Burst Time:%d  \t",burst_time[i]);

        temp[i] = burst_time[i];
    }

    
    fscanf(fp,"%d", &time_quantum);
    printf("\nEnter Time Quantum:%d\t",time_quantum);
    fp = fopen("C:\\Users\\KIIT\\Desktop\\b.txt", "w");
    if (fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fp, "\nProcess ID  Burst Time Turnaround Time  Waiting Time\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
            x--;
            fprintf(fp, "\nProcess[%d]\t %d \t\t%d \t\t%d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            wait_time = wait_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
            counter = 0;
        }
        if(i == limit - 1)
        {
            i = 0;
        }
        else if(arrival_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    average_wait_time = wait_time * 1.0 / limit;
    average_turnaround_time = turnaround_time * 1.0 / limit;
    fprintf(fp, "\n\nAverage Waiting Time:%f", average_wait_time);
    fprintf(fp, "\nAvg Turnaround Time:%f\n", average_turnaround_time);
    fclose(fp);
}

