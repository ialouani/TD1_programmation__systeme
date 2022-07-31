#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>//comme pour dlfcn.h
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>


int main(int argc, char** argv, char* env[]){
  execve(argv[1],argv+1,env);
  //ce programme lit sur son entree standard l'executable ecrivain
  //ce qu'il a ecrit
  //et execute soit affiche sur la sortie stdout le resultat
  //de l'ecrivain.
  return 0;
}
