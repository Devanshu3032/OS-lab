#include <stdio.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

int main() {
    int partition_size[MAX_PARTITIONS], partition_alloc[MAX_PARTITIONS];
    int process_size[MAX_PROCESSES], process_alloc[MAX_PROCESSES];
    int num_partitions, num_processes;

    printf("Enter number of partitions: ");
    scanf("%d", &num_partitions);

    printf("Enter sizes of each partition:\n");
    for (int i = 0; i < num_partitions; i++) {
        printf("Partition %d size: ", i + 1);
        scanf("%d", &partition_size[i]);
        partition_alloc[i] = 0; // 0 means free
    }

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter sizes of each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &process_size[i]);
        process_alloc[i] = -1; // -1 means not allocated
    }

    // First Fit Allocation
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_partitions; j++) {
            if (!partition_alloc[j] && partition_size[j] >= process_size[i]) {
                process_alloc[i] = j;
                partition_alloc[j] = 1;
                break;
            }
        }
    }

    // Output result
    printf("\nProcess Allocation Result (First Fit):\n");
    printf("Process No.\tProcess Size\tPartition Allocated\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (process_alloc[i] != -1)
            printf("%d\n", process_alloc[i] + 1); // partition number
        else
            printf("Not Allocated\n");
    }

    return 0;
}
