#include<stdio.h>
#include<dirent.h>
struct dirent *a ;
int main(){
    DIR *b ;
    b = opendir("./home");
    if(b = NULL){
        perror("ERROR PROCESS EXECUTION");
        return 1 ;
    }
    while((a = readdir(b)) != 0 ){
        printf("%s\n",a ->d_name);
    }
    closedir(b);
    return 1 ;
}