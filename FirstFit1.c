#include <stdio.h>
#define N 10

int main() {
    int part[N], proc[N], p_alloc[N], used[N] = {0};
    int n_part, n_proc;

    printf(" Enter number of Partitions: "); 
    scanf("%d", &n_part);
    for (int i = 0; i < n_part; i++) scanf("%d", &part[i]);

    printf(" Enter the Processes: "); scanf("%d", &n_proc);
    for (int i = 0; i < n_proc; i++) scanf("%d", &proc[i]);

    for (int i = 0; i < n_proc; i++) {
        p_alloc[i] = -1;
        for (int j = 0; j < n_part; j++) {
            if (!used[j] && part[j] >= proc[i]) {
                p_alloc[i] = j;
                used[j] = 1;
                break;
            }
        }
    }

    printf("\nProcess\tSize\tPartition\n");
    for (int i = 0; i < n_proc; i++) {
        printf("%d\t%d\t", i + 1, proc[i]);
        if (p_alloc[i] != -1) printf("%d\n", p_alloc[i] + 1);
        else printf("Not Allocated\n");
    }

    return 0;
}
