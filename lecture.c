#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int readFile(const char* pathname,int count, char* buf){
  int fd,byte,length=count;
  int len=0;
  fd=open(pathname,O_RDONLY);
  if(fd==-1){
    perror("open() failed");
    exit(1);
  }
  /*Read count bytes from the file*/
  while((byte=read(fd,buf,length))!=0){
    if(byte==-1){
      perror("read() failed");
      exit(1);
    }
    length=length-byte;
    buf=buf+length;
    len+=length;
  }
  close(fd);
  return len;
}


int main(int argc, char* argv[]){
  // char buf[5];//5 caracteres au moins dans le fichier en question.
  FILE* f=fopen("propre.txt","rw+");
  int compteur=0;
  while(fgetc(f) != EOF)
    compteur ++;
  //d'abord compter le nombre de caracteres.

  //bien allouer notre buffer.(memoire tampon)
  char* buf=calloc(sizeof(char),(compteur+1));
  //on se debarasse de values non initialisees quand on veut le strlen via
  //up dans gdb le main.///
  int len=  readFile("propre.txt",compteur,buf);
  //passer en parametre le fichier en question, le buffer et le compteur en $2.
  
  /* printf("%d\n\n\n",len);*/
  printf("%s\n",buf-len);
  free(buf);
  fclose(f);
  //c'en est direct!!!
  return 0;
}
