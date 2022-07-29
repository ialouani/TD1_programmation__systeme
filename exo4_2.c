#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#ifndef x
#define x 5
#endif

int write_number(long y){
  char buffer[100];//exactement juste 8 octets soit 8 cases suffisent.
  char s=y+'0';
  char const* y2=(char const*)&s;
  int w=write(STDOUT_FILENO,y2,strlen(y2));
  if(w<0){
    perror("Erreur d'ecriture .\n");
  }
  
  return 0;
}

int main(int argc, char** argv/*,char** envp*/){
  write_number(x);
  int i;
  long len=0;
  for(i=1;i<=argc-1;i++){
    len+=strlen(argv[i]);
  }
  
  char* s2="\n";
    int w2=write(STDOUT_FILENO,s2,strlen(s2));
    if(w2<0)
      perror("Erreur lors du retour chariot pour separer les parametres: ");

    /*  char s=len+'0';
    const char* ss=(const char*)&s;
    int w1=write(STDOUT_FILENO,ss,strlen(ss));
    if(w1<0)
    perror("Erreur ecriture nombre octets precedents:\n\n");*/

    /*long x2=len;
      write_number(x2);*/

    /*  char* s22="\n";
    int w22=write(STDOUT_FILENO,s22,strlen(s22));
    if(w22<0)
    perror("Erreur lors du retour chariot pour separer les parametres: ");*/

    fprintf(stdout,"value of the bytes:%ld\n",len);

  return 0;
}


