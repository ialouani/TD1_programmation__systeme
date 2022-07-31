#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>//comme pour dlfcn.h
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<string.h>

struct nopad{
  char c;
  long l;
};
//char c prendra 5 et c 'a'.

int main(int argc, char** argv, char** envp){
  struct nopad exemple;
  exemple.c='a';exemple.l=5;
  char *fd = "myfile.txt";
  struct stat *buf;

  buf = malloc(sizeof(struct stat));

  stat(fd, buf);
  int size = buf->st_size;
  printf("%d",size);

  free(buf);
  return 0;
}
