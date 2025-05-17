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
        printf("%s\n", a -> d_name);
    }
    closedir(b) ;
}