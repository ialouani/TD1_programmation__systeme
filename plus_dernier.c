//#define _POSIX_SOURCE
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
//#undef _POSIX_SOURCE
#include<stdio.h>

#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>


#include<stdlib.h>
#include<string.h>

void creating_files(char f[]){
  int fd;
  fd=creat(f,S_IRUSR|S_IWUSR);//autoriser la lecture et l'ecriture apres.
  if(fd<0)
    perror("creat() error");
  return;
}

int main(){
  char f[]="new___3.txt";
  creating_files(f);
  return 0;
}
