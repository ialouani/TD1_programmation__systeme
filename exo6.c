#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

/*
toujours include sys/types.h et include sys/stat.h et include unistd.h
*/


int main(int argc, char **argv){
  int fd1, fd2, rc;
  //on charge les 2 descripteurs de fichiers.
  char buf;
  if(argc != 3) {
    fprintf(stderr, "Syntaxe: %s f1 f2\n", argv[0]);
    exit(1);
  }
  fd1 = open(argv[1], O_RDONLY);
  //on recupere un pointeur ptr_t vers une partie de la table de descripteurs
  //de fichiers.
  if(fd1 < 0) {
    perror("open(fd1)");
    exit(1);
  }
  fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if(fd2 < 0) {
    perror("open(fd2)");
    exit(1);
  }
  while(1) {
    rc = read(fd1, &buf, 1);
    //la fonction read de prototype: ssize_t read(int fd, void* buf, size_t count)
    //Ca lit 1 ($3) octets (characteres) depuis le descripteur de fichier fd1
    //et stocke ce dernier dans buf.
    if(rc < 0) {
      perror("read");
      exit(1);
    }
    if(rc == 0)
      break;
    rc = write(fd2, &buf, 1);
    if(rc < 0) {
      perror("write");
      exit(1);
    }
    if(rc != 1) {
      fprintf(stderr, "Écriture interrompue");
      exit(1);
    }
  }
  close(fd1);
  close(fd2);//UNE SEULE FOIS.///
  //on fait les close
  //vu qu'on doit obligeatoirement fermer les descripteurs pour enlever
  //tous les ptr_t appels systemes qui permettent d'acceder aux metadata
  //d'un fichier dans une table de fichier dans la mémoire RAM.
  return 0;
  //prototype: int close(int fd);
}
