#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
 
    int file=0;
    if((file=open(argv[1],O_RDONLY)) < -1)
       return 1;
 
    struct stat fileStat;
    if(fstat(file,&fileStat) < 0)    
      return 1;

    if (S_ISDIR(fileStat.st_mode))
      printf("C'est un répertoire");
    if (S_ISLNK(fileStat.st_mode))
      printf("lien symbolique");
    if(! (S_ISDIR(fileStat.st_mode) && ! S_ISLNK(fileStat.st_mode)))
      printf("C'est un fichier normal.");
    printf("\n\n");
    /*
else printf("C'est un fichier normal");
    */
    return 0;
}
