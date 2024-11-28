#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n]; // Remaining burst times
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    int t = 0; // Current time

    // Traverse processes in round robin manner
    while (1) {
        int done = 1; // To check if all processes are done
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is still a process to execute

                if (rem_bt[i] > quantum) {
                    t += quantum; // Increase time by quantum
                    rem_bt[i] -= quantum; // Reduce burst time by quantum
                } else {
                    t += rem_bt[i]; // Process can finish in this cycle
                    wt[i] = t - bt[i]; // Calculate waiting time
                    rem_bt[i] = 0; // Process is finished
                }
            }
        }

        if (done == 1) {
            break; // All processes are done
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = burst time + waiting time
    }
}

void findAverageTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes   Burst time   Waiting time   Turnaround time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {10, 5, 8}; // Burst times for each process
    int quantum = 2; // Time quantum

    findAverageTime(processes, n, burst_time, quantum);

    return 0;
}
