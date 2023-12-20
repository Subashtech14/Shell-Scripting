#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time, end_time;
    double burst_time;

    // Record the start time
    start_time = clock();

    // Place your code or process here

    // Record the end time
    end_time = clock();

    // Calculate burst time in seconds
    burst_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Burst time: %f seconds\n", burst_time);

    return 0;
}
