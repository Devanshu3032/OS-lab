#include<stdio.h>
#include<stdlib.h>

int mutex = 1 ;
int full = 0 ;
int empty = 3 ;
int x = 0 ;

void producer(){
  mutex-- ;
  full++ ;
  empty-- ;
  x++ ;
  printf("Producer produce item %d\n",x);
  mutex++;
}

void consumer(){
    mutex-- ;
    full-- ;
    empty++ ;
    printf("consumer consumed item %d\n", x);
    x-- ;
    mutex++ ;
}
int main(){
    printf("\n 1.Press 1 for producer\n 2.Press 2 for consumer\n 3.Press 3 for exit.\n");

int i , n ;
for(i = 1 ; i > 0; i++ ){
    printf("Enter your choise :");
    scanf("%d" ,&n);

    switch(n){
        case 1 : 
        if((mutex == 1 ) && (empty != 0)){
            producer();
        }
        else{
            printf("Buffer is full");
        }

        break ;
        case 2 : 
        if((mutex == 1) && (full != 0)){
            consumer();
        }
        else{
            printf("Buffer is Full ");
        }

        break ;

        case 3 : 
        exit(0) ;
        break ;
    }
}
}