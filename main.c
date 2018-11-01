#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
  DIR* d;
  int size = 0;
  d = opendir(".");
  struct dirent *file; 
  
  while(file = readdir(d)){
    if (file->d_type == DT_DIR){
      printf("subdirectory: %s\n",file->d_name); 
    }
    if (file->d_type == DT_REG){
      printf("file: %s\n",file->d_name);
      struct stat stats;
      stat(file->d_name, &stats);
      size += stats.st_size;
    }
  }
  printf("Directory size: %d\n",size);

  closedir(d);
}
