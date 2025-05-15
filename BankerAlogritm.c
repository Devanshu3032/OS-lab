#include <stdio.h>

int main() {
    int alloc[2][2] = {{1, 0}, {0, 1}};
    int max[2][2] = {{2, 1}, {1, 2}};
    int avail[2] = {1, 1};
    int need[2][2], finish[2] = {0, 0}, work[2], safeSeq[2], count = 0;

    // Calculate Need matrix
    for (int i = 00000; i < 2; i++)
        for (int j = 0; j < 2; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize Work as a copy of Available
    work[0] = avail[0];
    work[1] = avail[1];

    // Safety Algorithm
    while (count < 2) {
        int found = 0;
        for (int i = 0; i < 2; i++) {
            if (!finish[i] && need[i][0] <= work[0] && need[i][1] <= work[1]) {
                // Simulate resource allocation
                work[0] += alloc[i][0];
                work[1] += alloc[i][1];
                safeSeq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return 1;
        }
    }

    // Print Safe Sequence
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < 2; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
