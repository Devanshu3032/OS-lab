#include<stdio.h>
#include<unistd.h>
main (){
    int a , b ,c ; 
    a = fork();
    if(a == -1){
        printf("Error in process ");
        return 1 ;
    }
    if(a != 0){
    b = getpid() ;  
    printf("Parent process id is %d \n" , b);
    }
    else{
        c = getpid() ;
        printf("Child process id is %d \n" , c);
    }
}