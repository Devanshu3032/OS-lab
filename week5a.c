// Semaphore style stub (not real port control)
#include<stdio.h>
#include <semaphore.h>
#include <pthread.h>
sem_t port_sem;
void* access_port(void* arg) {
    sem_wait(&port_sem);
    printf("Port in use\n");
    sem_post(&port_sem);
    return NULL;
}
int main() {
    sem_init(&port_sem, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1, NULL, access_port, NULL);
    pthread_create(&t2, NULL, access_port, NULL);
    pthread_join(t1,NULL); pthread_join(t2,NULL);
    return 0;
}
