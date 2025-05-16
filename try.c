#include<stdio.h> 
#include<dirent.h> 
struct dirent *a ;
int main(){
    DIR *b ; 
    b = opendir("./home");
    if( b == NULL){
        perror("Errorr");
    }
    whie
}