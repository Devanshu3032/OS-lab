#include<stdio.h> 
#include<dirent.h> 
struct dirent *a ;
int main(){
    DIR *b ; 
    b = opendir("./home");
    if( b == NULL){
        perror("Errorr");
    }
    while(( a= readdir(b)) != 0){
        printf("%dd\n", a -> d_name);
    }
    closedir(b) ;
}