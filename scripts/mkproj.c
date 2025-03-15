#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 256

int main(int argc, char *argv[]) {

  char *dossiers[] = {
    "/assets/imgs",
    "/assets/icons",
    "/assets/fonts",
    "/css",
    "/js/modules"
  };

  char mkdir[BUFF_SIZE];
  snprintf(mkdir, BUFF_SIZE, "mkdir %s", argv[1]);
  system(mkdir);

  int i = 0;
  while (i < (sizeof(dossiers) / sizeof(dossiers[0]))) {
    snprintf(mkdir, BUFF_SIZE, "mkdir -p %s%s", argv[1], dossiers[i]);
    system(mkdir);
    i++;
  }


  return 0;
}
