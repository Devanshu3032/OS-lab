#include <stdio.h>
#include<dirent.h>
struct dirent *a ;
int main() {
   DIR *b ;
   b = opendir("./home");
   if(b == NULL){
       perror("File not found");
       
   }
   while ((a = readdir(b)) != NULL){
       printf("%s\n",a ->d_name);
   }
   closedir(b) ;
   
}