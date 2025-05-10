#include <stdio.h>
#include<dirent.h>
struct dirent *a ;
int main() {
   DIR *b ;
   b = opendir("./home");
   if(b == NULL){
       perror("File not found");
       return 1 ;
   }
   while ((a = readdir(b)) != NULL){
       printf("%s\n",a ->d_name);
   }
   closedir(b) ;
   return 1 ;
}