#include <stdio.h>

void priorityScheduling(int processes[], int priorities[], int n) {
    int waiting_time = 0;
    int turnaround_time = 0;

    printf("Process\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        turnaround_time += waiting_time + processes[i];
        printf("%d\t%d\t\t%d\n", i + 1, waiting_time, turnaround_time);
        waiting_time += processes[i];
    }
}

int main() {
    int processes[] = {8, 6, 10, 12};
    int priorities[] = {3, 5, 1, 4};
    int n = sizeof(processes) / sizeof(processes[0]);

    // Sort processes based on priority (Lower priority number implies higher priority)
    // (This step is usually done dynamically during execution)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priorities[j] > priorities[j + 1]) {
                int temp = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    priorityScheduling(processes, priorities, n);

    return 0;
}
