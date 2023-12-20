#include <stdio.h>

void sjf(int processes[], int n) {
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
    int processes[] = {6, 8, 7, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    // Sort processes in ascending order of burst time (SJF)
    // (This step is usually done dynamically during execution)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j] > processes[j + 1]) {
                int temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    sjf(processes, n);

    return 0;
}
