#include<stdio.h>
#include<dirent.h>
struct dirent *dptr ;
int main()
{
    DIR *dirp;
    dirp = opendir("./hme");
    if (dirp == NULL)
    {
        perror("lund la");
        return 1;
    }
    while ((dptr = readdir(dirp)) != NULL)
    {
        printf("%s\n", dptr->d_name);
    }
    closedir(dirp);
    return 0;
}