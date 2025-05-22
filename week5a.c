/ Online C compiler to run C program online
#include <stdio.h>
#include<pthread.h> 
#include<semaphore.h>
#define MAX_PORT 3 
#include<unistd.h>
sem_t ports_semaphore ;
void *open_port(void *arg){
    printf("process %id: Trying to open port....\n",(long)arg);
    sem_wait(&ports_semaphore);
    printf("process %id : Port open ..\n ",(long)arg);
    sleep(2) ;
    printf("process %id: closing port\n",(long)arg );
    sem_post(&ports_semaphore) ;
    return NULL ; 
    
}
int main () {
    pthread_t threads[5] ; 
    sem_init(&ports_semaphore,0,MAX_PORT);
    for(long i = 0 ; i < 5 ; i++){
        pthread_create(&threads[i],NULL,open_port,(void*)i);
    }
    for(int i = 0 ; i < 5 ; i++){
        pthread_join(threads[i] , NULL) ;
    }
    
    sem_destroy(& ports_semaphore) ;
    return 0 ;
}