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

int main(int argc, char* argv[]){
  int fd;
  char f[]="new___3.txt";
  if((fd=creat(f,S_IWUSR))<0){
    perror("creat() error");
      }
  else{
    close(fd);
    if(unlink(f)!=0){
      perror("unlink() error");
    }
  }
  return 0;
}
  
