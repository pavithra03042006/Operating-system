#include<stdio.h>
#define MAX 50

int main() {
    int page[MAX], i, n, f, ps, off, pno;
    int choice = 0;
    printf("\nEnter the number of pages in memory: ");
    scanf("%d", &n);
    printf("\nEnter page size: ");
    scanf("%d", &ps);
    printf("\nEnter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < n; i++) {
        page[i] = -1;
    }
    printf("\nEnter the page table\n");
    printf("(Enter -1 if the page is not present in any frame)\n\n");
    printf("\npageno\tframeno\n-------\t-------");
    for(i = 0; i < n; i++) {
        printf("\n%d\t\t", i);
        scanf("%d", &page[i]);
    }
    do {
        printf("\nEnter the logical address (page number and offset): ");
        scanf("%d%d", &pno, &off);
        if(page[pno] == -1) {
            printf("\nThe required page is not available in any frame.");
        } else {

            printf("\nPhysical address (frame number and offset): %d, %d", page[pno], off);
        }
        printf("\nDo you want to continue (1/0)? ");
        scanf("%d", &choice);
    } while(choice == 1);
    return 0;
}

