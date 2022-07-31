

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
     
    int main() {
     if(access("ACCESS.C",F_OK)==0) {
      printf("Le fichier «ACCESS.C» existe !\n");
     } else {
      printf("Le fichier «ACCESS.C» n'existe pas !\n");
     }
     return 0;
    }

