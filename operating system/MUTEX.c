#include <stdio.h>
#include <stdlib.h>

int tph, howhung, hu[20], cho;

void one() {
    printf("\nAllow one philosopher to eat at any time\n");
    for (int i = 0; i < howhung; i++) {
        printf("\nP%d is granted to eat", hu[i]);
        for (int x = i + 1; x < howhung; x++)
            printf("\nP%d is waiting", hu[x]);
    }
}

void two() {
    printf("\nAllow two philosophers to eat at the same time\n");
    for (int i = 0; i < howhung; i++) {
        for (int j = i + 1; j < howhung; j++) {
            if (abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != 4) {
                printf("\n\nCombination: P%d and P%d granted to eat\n", hu[i], hu[j]);
                for (int x = 0; x < howhung; x++) {
                    if (hu[x] != hu[i] && hu[x] != hu[j])
                        printf("P%d is waiting\n", hu[x]);
                }
            }
        }
    }
}

int main() {
    printf("\nDINING PHILOSOPHER PROBLEM");
    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &tph);

    printf("How many are hungry: ");
    scanf("%d", &howhung);

    if (howhung == tph) {
        printf("\nAll philosophers are hungry... Deadlock will occur!\nExiting...\n");
        return 0;
    }

    printf("Enter positions of hungry philosophers:\n");
    for (int i = 0; i < howhung; i++) {
        printf("Philosopher %d position: ", i + 1);
        scanf("%d", &hu[i]);
    }

    while (1) {
        printf("\n1. One can eat at a time\n2. Two can eat at a time\n3. Exit\nEnter your choice: ");
        scanf("%d", &cho);
        switch (cho) {
            case 1: one(); break;
            case 2: two(); break;
            case 3: printf("\nExiting...\n"); return 0;
            default: printf("\nInvalid option, try again.\n");
        }
    }

    return 0;
}
