#include<stdio.h> ;
#include<unistd.h>;
main(){
 int a , b ,c ;
 a = getpid() ; 
 if(a == 0){
    printf("Error in process "); 
 }
 if(a != 0){
    a= getpid() ;
    printf("process id is %d\n",a);
 }

}