#include <stdio.h>

void cfs(int processes[], int n) {
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
    int n = sizeof(processes) / sizeof(processes[0]);

    // The Completely Fair Scheduler in the Linux kernel uses a more sophisticated approach
    // involving virtual runtime and other parameters. This simple example does not capture
    // the complexity of the actual CFS algorithm.

    cfs(processes, n);

    return 0;
}
