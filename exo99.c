#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char** argv){
  int result;
  if (argc!=2){
    fprintf(stderr,"Usage: ./a.out fifoname\n");
    exit(1);
  }
  result=mknod(argv[1],S_IRUSR|S_IWUSR|S_IFIFO,0);
  if(result<0){
    perror("mknod");
    exit(2);
  }
}
