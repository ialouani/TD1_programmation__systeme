#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int indice_max(char* args[],int len){
  int index=0;
  for(int j=0;j<=len;j++){
    if(strlen(args[j])>strlen(args[index])) index=j;
  }
  return index;
}



int main(int argc, char** argv)
{


  //char* message=(char*)malloc(sizeof(*message));
  //strcpy(message,argv[1]);
  for(int i=1;i<=argc-1;i++){

        char* message=(char*)malloc(sizeof(*message));
    strcpy(message,argv[i]);

    //read(STDIN_FILENO, argv[i], sizeof(argv[i])-1);
  
    //message=realloc(message,sizeof(argv[1])-1);
    //pour le valgrind seulement les 2 types classiques d'erreur(pas de free;on le rappelle).
    int w=write(STDOUT_FILENO, argv[i], strlen(argv[i]));
    if(w<0) perror("Erreur lecture depuis l'entree et l'ecriture a la sortie: \n");

    const char* ss="\n";
    int ww=write(STDOUT_FILENO,ss,strlen(ss));
    if(ww<0) perror("Erreur de retour \n");

    free(message);//et voila!
  }
    return 0;
}
