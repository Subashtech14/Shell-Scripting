#include <stdio.h>

void roundRobin(int processes[], int n, int time_quantum) {
    int waiting_time = 0;
    int turnaround_time = 0;

    printf("Process\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        int remaining_time = processes[i];
        while (remaining_time > 0) {
            if (remaining_time > time_quantum) {
                waiting_time += time_quantum;
                remaining_time -= time_quantum;
            } else {
                waiting_time += remaining_time;
                remaining_time = 0;
            }
        }
        turnaround_time = waiting_time + processes[i];
        printf("%d\t%d\t\t%d\n", i + 1, waiting_time, turnaround_time);
    }
}

int main() {
    int processes[] = {10, 6, 8, 12};
    int n = sizeof(processes) / sizeof(processes[0]);
    int time_quantum = 4;

    roundRobin(processes, n, time_quantum);

    return 0;
}
