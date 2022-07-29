#include<errno.h>//pour la fonction perror.(char const* s en argument)
#include<stdio.h>
#include<unistd.h>//pour la fonction write qui est un appel systeme
#include<string.h>//pour strlen pour les arguments du syscall: write(2).


void affichage(char** arguments){
  int i;
  for(i=0;arguments[i]!=NULL;i++){
    //pas de sizeof(arguments) qui est 8!!(via gdb --reconnaissance)
    //arguments[i]=0x0 soit NULL sur gdb point d'arret dans while modifie donc.
    const char* s1=arguments[i];
    const char* s2="\n";
    int w1=write(STDOUT_FILENO,s1,strlen(s1));
    if(w1<0)
      perror("Erreur lors de l'ecriture: ");
    int w2=write(STDOUT_FILENO,s2,strlen(s2));
    if(w2<0)
      perror("Erreur lors du saut ligne pour separation: ");
  }
    return;
}
int main(int argc, char** argv){
  char* nom1="ismail";
  char* nom2="meryem";
  char* argss[]={nom1,nom2,NULL};
  affichage(argss);
  return 0;
}
