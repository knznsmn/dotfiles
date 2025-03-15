#include <stdio.h>
#include <stdlib.h>

void header(FILE *f);
void writer(int, char *);
char *fichier(int, char *argv[]);

#define BUFF_SIZE 256
typedef enum Files { HTML, CSS, JS } Files;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("\nUsage:\n\n\t%s <project/name>\n\n", argv[0]);
  }
  else {
    char *dossiers[] = {
      "/css",
      "js",
      "/js/modules",
      "/assets/imgs",
      "/assets/icons",
      "/assets/fonts",
    };

 
    char cmd[BUFF_SIZE];
    char *dir;
    snprintf(cmd, BUFF_SIZE, "mkdir %s", argv[1]);
    system(cmd);
    printf("Created the root directory '%s'.\n", argv[1]);
    dir = fichier(HTML, argv);
    writer(HTML, dir);
    
    int i = 0;
    while (i < (sizeof(dossiers) / sizeof(dossiers[0]))) {
      snprintf(cmd, BUFF_SIZE, "mkdir -p %s/%s", argv[1], dossiers[i]);
      system(cmd);
      printf("Directory '%s' created.\n", dossiers[i]);
      if (i == 0) {
        snprintf(cmd, BUFF_SIZE, "touch %s/%s/style.css", argv[1], dossiers[i]);
        system(cmd);
        printf("Created the stylesheet.\n");
      }
      else if (i == 1) {
        snprintf(cmd, BUFF_SIZE, "touch %s/%s/main.js", argv[1], dossiers[i]);
        system(cmd);
        printf("Created the script file.\n");
      }
      i++;
    }
   
  }
/*
    i = 0;
    char *fichier[BUFF_SIZE];
    while (i <  && fichiers[0] {
      fichier[0]
    }
  }
*/
  return 0;
}

void header(FILE *f) {
  fputs("/*.\n", f);
}


void writer(int d, char *dirname) {

  FILE *f = fopen(dirname, "w");

  switch (d) {
    case HTML:
      header(f);
      fputs("<html>\n", f);
      fputs("</html>\n", f);
    break;
  case CSS:
      header(f);
      fputs("/* Global resets\n", f);
    break;
  case JS:
      header(f);
      fputs("// Function Hall\n", f);
      break;
   default:
      printf("Something's wrong with the argument.\n");
  }

  fclose(f);
}

char *fichier(int d, char *argv[]) {
  char *fichiers[] = {
    "/index.html",
    "/css/style.css",
    "/js/main.js",
  };
  int i = 0;
  int j = 0;
  static char dir[BUFF_SIZE];
  while (i < BUFF_SIZE - 1 && argv[1][i] != '\0') {
    dir[i] = argv[1][i];
    i++;
  }
  while (i < BUFF_SIZE - 1 && fichiers[d][j] != '\0') {
    dir[i] = fichiers[d][j];
    i++;
    j++;
  }
  dir[i] = '\0';

  return dir;
}
