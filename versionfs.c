#include "versionfs.h"

FILE *
  verfs_fopen(const char *filename, const char *mode, unsigned long int version){
  // seu código aqui!
  return NULL;
}


int
  vfs_fclose(FILE *stream){
  // seu código aqui!
  return -1;
}

void
  verfs_fcloseall(void){
  // seu código aqui!
}

unsigned long int
  vfs_getversions(const char *filename){
  // seu código aqui!
  return 0;
}

int
  verfs_removeversion(const char *filename, unsigned long int version){
  // seu código aqui!
  return -1;
}

int
  verfs_removeall(const char *filename){
  // seu código aqui!
  return -1;
}
