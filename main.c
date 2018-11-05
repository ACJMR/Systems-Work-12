#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char * argv[]){
  DIR* d;
  char * s;
  int size = 0;
  s = argv[1];

  if (argc == 1){
    char s2[256];
	printf("Please enter directory: ");
    scanf("%s",s2);
    s = s2;
  }
  
  d = opendir(s);
  if (errno > 0){
    printf("Error: %s\n",strerror(errno));
    return 0;
  }
  struct dirent *file;

  printf("Examining directory: %s\n",s);
  printf("---------------------------\n");

  while((file = readdir(d))){
    if (file->d_type == DT_DIR){
      printf("Directory: %s\n",file->d_name);
    }
    if (file->d_type == DT_REG){
      printf("File: %s\n",file->d_name);
      struct stat stats;
      stat(file->d_name, &stats);
      size += stats.st_size;
    }
  }
  printf("Directory size: %d\n",size);
  printf("-----------------------------\n");

  closedir(d);
}
