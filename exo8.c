#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>//comme pour dlfcn.h
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>


char* write_number(){
  char* s=malloc(sizeof(*s));
  srand(time(NULL));
  int random_number=(int)rand();

  s=(char*)&random_number;
  return s;
}

int main(int argc, char** argv, char** envp){
  const char* s=(const char*)write_number();
  //int* ss=(int*)s;
  char buf;
  int fd;
  char* s2=malloc(sizeof(*s2));
  FILE* f=fopen("file_intermediaire","rw+");
  fputs(s,f);
  char c;
  fd=open("file_intermediaire",O_RDONLY);
  int i=0;
  while(read(fd,&c,1)>0){
    s2[i]=c;i++;
  }
  close(fd);
  printf("%d\n",*(int*)s2);
  return 0;
}
