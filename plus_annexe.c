
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv){
  int fd,rc;
  char buf;
  fd = open(argv[1], O_WRONLY , 0666);
  const char* s="abcde";
  write(fd,s,strlen(s));
  close(fd);
  return 0;
}

