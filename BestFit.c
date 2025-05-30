#include <stdio.h>
#define N 10

int main() {
    int part[N], proc[N], alloc[N], used[N] = {0};
    int n_part, n_proc;

    printf("Enter number of partitions: ");
    scanf("%d", &n_part);
    printf("Enter sizes of partitions:\n");
    for (int i = 0; i < n_part; i++) scanf("%d", &part[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n_proc);
    printf("Enter sizes of processes:\n");
    for (int i = 0; i < n_proc; i++) scanf("%d", &proc[i]);

    for (int i = 0; i < n_proc; i++) {
        int best = -1;
        for (int j = 0; j < n_part; j++) {
            if (!used[j] && part[j] >= proc[i]) {
                if (best == -1 || part[j] < part[best])
                    best = j;
            }
        }
        if (best != -1) {
            alloc[i] = best;
            used[best] = 1;
        } else {
            alloc[i] = -1;
        }
    }

    printf("\nProcess\tSize\tPartition\n");
    for (int i = 0; i < n_proc; i++) {
        printf("%d\t%d\t", i + 1, proc[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
