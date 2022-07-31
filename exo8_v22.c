#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>//comme pour dlfcn.h
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<sys/cdefs.h>

int main(int argc, char** argv, char* env[]){
  //char* s2=write_number();
  //int rslt=*(int*)s2;
  int file_desc=open((const char*)stdout,O_WRONLY | O_APPEND);
    dup2(file_desc,1);
  
  execve(argv[1],argv+1,env);
  //utilisation de dup(2)
  //via redirection de ce que fera ./a sur le ./a.out
  //on fait un execve qui va executer ./a
  //mais tous est redirigée vers le stdout avec dup2(file_desc,1).
  return 0;
}
  
