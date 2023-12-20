#include <stdio.h>
#include <stdlib.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for the first process is always 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
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

void printTurnaroundTime(int tat[], int n) {
    printf("Turnaround Time: ");
    for (int i = 0; i < n; i++)
        printf("%d ", tat[i]);
    printf("\n");
}

float findAverageTime(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    
    return (float) total / n;
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

    int *tat = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory
    if (tat == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    findWaitingTime(processes, n, burst_time, wt);
    findTurnaroundTime(processes, n, burst_time, wt, tat);

    // Displaying the results
    printProcesses(processes, n);
    printBurstTime(burst_time, n);
    printWaitingTime(wt, n);
    printTurnaroundTime(tat, n);

    printf("Average Waiting Time: %f\n", findAverageTime(wt, n));
    printf("Average Turnaround Time: %f\n", findAverageTime(tat, n));

    // Free dynamically allocated memory
    free(burst_time);
    free(wt);
    free(tat);

    return 0;
}
