#include <stdio.h>
int main() {
    int n, bt[10], wt[10], tat[10], rem_bt[10], i, time_quantum, time = 0;
    float total_wt = 0, total_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter the Time Quantum: ");
    scanf("%d", &time_quantum);
    int completed = 0;
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] <= time_quantum) {
                    time += rem_bt[i];
                    tat[i] = time;
                    rem_bt[i] = 0;
                    completed++;
                } else {
                    rem_bt[i] -= time_quantum;
                    time += time_quantum;
                }
            }
        }
    }
    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    return 0;
}
