#include<errno.h>//pour la fonction perror.(char const* s en argument)
#include<stdio.h>
#include<unistd.h>//pour la fonction write qui est un appel systeme
#include<string.h>//pour strlen pour les arguments du syscall: write(2).


int main(int argc, char** argv){
  int i;
  for(i=1;i<=argc-1;i++){
    const char* s=argv[i];
    char* s2="\n";
    int w=write(STDOUT_FILENO,s,strlen(s));
    int w2=write(STDOUT_FILENO,s2,strlen(s2));
    //ecriture sur la sortie standard d'un des arguments du programme.
    if(w<0)
      perror("Erreur lors de l'écriture: ");
    //sinon w<0 retour de write alors on programme notre propre erreur nom.
    if(w2<0)
      perror("Erreur lors du retour chariot pour separer les parametres");
  }
  return 0;
}
