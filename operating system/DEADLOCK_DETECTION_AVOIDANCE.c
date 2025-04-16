#include <stdio.h>

#define MAX 10

int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX];
int avail[MAX], finish[MAX], safeSeq[MAX];
int np, nr;

void calculateNeed() {
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe() {
    int work[MAX], count = 0;
    for (int i = 0; i < nr; i++)
        work[i] = avail[i];
    for (int i = 0; i < np; i++)
        finish[i] = 0;

    while (count < np) {
        int found = 0;
        for (int i = 0; i < np; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < nr; j++) {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == nr) {
                    for (int k = 0; k < nr; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
            return 0; // No safe sequence
    }
    return 1; // Safe sequence found
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter number of resources: ");
    scanf("%d", &nr);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources:\n");
    for (int i = 0; i < nr; i++)
        scanf("%d", &avail[i]);

    calculateNeed();

    printf("\nChecking system state...\n");

    if (isSafe()) {
        printf("\nNo Deadlock detected. Safe sequence: ");
        for (int i = 0; i < np; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("\nDeadlock detected. No safe sequence possible.\n");
    }

    return 0;
}
