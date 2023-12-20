#include <stdio.h>
#include <stdlib.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for the first process is always 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void printProcesses(int processes[], int n) {
    printf("Processes: ");
    for (int i = 0; i < n; i++)
        printf("%d ", processes[i]);
    printf("\n");
}

void printBurstTime(int bt[], int n) {
    printf("Burst Time: ");
    for (int i = 0; i < n; i++)
        printf("%d ", bt[i]);
    printf("\n");
}

void printWaitingTime(int wt[], int n) {
    printf("Waiting Time: ");
    for (int i = 0; i < n; i++)
        printf("%d ", wt[i]);
    printf("\n");
}

float findAverageWaitingTime(int wt[], int n) {
    int total_wt = 0;
    for (int i = 0; i < n; i++)
        total_wt += wt[i];
    
    return (float) total_wt / n;
}

int main() {
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]);

    int *burst_time = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory
    if (burst_time == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Example burst times
    burst_time[0] = 6;
    burst_time[1] = 8;
    burst_time[2] = 7;
    burst_time[3] = 3;
    burst_time[4] = 4;

    int *wt = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory
    if (wt == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    findWaitingTime(processes, n, burst_time, wt);

    // Displaying the results
    printProcesses(processes, n);
    printBurstTime(burst_time, n);
    printWaitingTime(wt, n);

    printf("Average Waiting Time: %f\n", findAverageWaitingTime(wt, n));

    // Free dynamically allocated memory
    free(burst_time);
    free(wt);

    return 0;
}
