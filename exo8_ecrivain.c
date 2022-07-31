#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>//comme pour dlfcn.h
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<sys/cdefs.h>

char* write_number(){
   char* s=malloc(sizeof(*s));
  srand(time(NULL));
  int random_number=(int)rand();

  s=(char*)&random_number;
  return s;
}

//ce qui est produit ici doit passer sur argv de exo8_lecteur.

int main(int agrc, char** argv,char* env[]){
  char* s1=write_number();
  
  printf("%d\n",*(int*)s1);
  return 0;
}
