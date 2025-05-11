#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
struct dirent *a;
 int main(){
    DIR *b ; 
    b = opendir("./home");
    if(b == NULL){
        perror("NOT FOUND ");
        return 1 ;
    }
    while((a = readdir(b)) != NULL){
        printf("%s\n" , a->d_name);
    }
    closedir(a) ;
    return 0 ;
}