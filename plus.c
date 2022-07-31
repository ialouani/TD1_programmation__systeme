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
  char f[]="new.txt";
  creating_files(f);
  /*const char* s="abcde";
  int fd=open("new.txt",O_RDWR);//oubien O_WRONLY car on veut juste ecrire 
avec le int mode a 0666 en octal comme prevu.
  write(fd,s,strlen(s));
  close(fd);*/
  return 0;
}
