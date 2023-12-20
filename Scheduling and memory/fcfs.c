#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main() {
    int i, n, *bt, *wt, *tat;
    float avgtat = 0, avgwt = 0;

    // Input: Number of processes
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);

    // Dynamic memory allocation for burst time, waiting time, and turnaround time arrays
    bt = (int*)malloc(n * sizeof(int));
    wt = (int*)malloc(n * sizeof(int));
    tat = (int*)malloc(n * sizeof(int));

    // Input: Burst time for each process
    printf("\n Enter the burst time for each process \n");
    for (i = 0; i < n; i++) {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;

    // Output: Display process details
    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i, bt[i], wt[i], tat[i]);
    }

    // Output: Display average waiting time and average turnaround time
    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    // Output: Display Gantt chart
    printf("\n GAANT CHART \n");
    printf("---------------\n");
    for (i = 0; i < n; i++) {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], i, tat[i]);
    }

    // Free allocated memory
    free(bt);
    free(wt);
    free(tat);

    return 0;
}
