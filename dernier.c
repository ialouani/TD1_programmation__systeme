#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include<stdlib.h>

int main(void){
  DIR* pDIR;
  pDIR = opendir("./");
  if ( pDIR == NULL ) {
    perror(" o p e n d i r ( ) f a i l e d ");
    exit( -1 );
  }
  struct dirent* pDirEnt;
  pDirEnt = readdir( pDIR );
  while ( pDirEnt != NULL ) {
    printf( "%s \n", pDirEnt->d_name );
    pDirEnt = readdir( pDIR );
  }
  closedir( pDIR );
  return 0;
}
