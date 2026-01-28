

#include <stdio.h>

int main() {
    int n = 3;
    int bt[3] = {5, 3, 8};   // Burst times
    int rem_bt[3];
    int at[3] = {0, 0, 0};  // Arrival times
    int ct[3] = {0}, tat[3], wt[3];
    int tq = 2;
    int time = 0;
    int completed = 0;

    // Copy burst times
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    // Round Robin Scheduling
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    printf("Process\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}


