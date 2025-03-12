#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, j, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", p[i]);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sort by priority
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(pri[i] > pri[j]) {
                // Swap priority
                temp = pri[i]; pri[i] = pri[j]; pri[j] = temp;
                // Swap burst time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // Swap process ID
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    tatavg = tat[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
