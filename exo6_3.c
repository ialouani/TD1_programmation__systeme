#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



int main(void) {

    pid_t c_pid = fork();
    //duplication=>heritage et creation d'un processus fils avec
    //le meme descripteur de fichier.
    //fork() retourne 0 pour le fils et le getpid(fils) POUR le parent.
    //les deux entrent dans le deuxième if.
    //LE parent gagne.
    //wait(NULL) fait en sorte que l'execution du processus fils soit terminee
    //pour terminer le processus père.
    //il teste (le processus fils) et entre dans le if c_pid==0.
    //Notons que ca represente le même descripteur de fichier donc
    //le père dans stdout a avance d'un certain nombre de caracteres; il en est
    //de meme pour le fils qui commence la ou le père a fini(avec un saut de
    //ligne compris bien sur).
    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {
        printf("printed from child process - %d\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        printf("printed from parent process - %d\n", getpid());
        wait(NULL);
    }

    exit(EXIT_SUCCESS);
}
