#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char** argv){
  FILE* f=fopen("file","rw+");
  for(int i=1;i<=argc-1;i++){
    fputs(argv[i],f);
    fputc('\n',f);
  }

  char c;
  int fd;

  fd = open("file", O_RDONLY);

  if (fd == -1){
  perror("impossible d'ouvrir le fichier\n");
  exit(1);
 }

  while ( read(fd, &c, 1) > 0 ){
    const char* s=(const char*)&c;
    write(STDOUT_FILENO,s,strlen(s));
    //putchar(c) (sortie standard obligée).
  }

  close(fd);
  
  return 0;
}







      
