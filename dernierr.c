#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
 
int main(void)
{
   struct dirent *lecture;
   DIR *rep;
   rep = opendir("/");
   while ((lecture = readdir(rep)))
   {
      printf("FICHIER: %s\n", lecture->d_name);
   }
   closedir(rep);
 
   return 0;
}
