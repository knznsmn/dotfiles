// Create a fresh project directory

#include <stdio.h>
#include <sys/stat.h>


void writer(int fich, FILE *f);
void creator(int doss, char *argv[]);


#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

  if (argc < 2)
    printf("\nUsage:\n\n\t%s <path/to/project>\n", argv[0]);
  else {
    
    char *files[] = {"/index.html", "./css/style.css", "./js/main.js"};

    mkdir(argv[1], 0755);

    FILE *f = fopen(dir, "w");
      writer(1, f);
    fclose(f);
  }
  return 0;
}
// Function Hall
void writer(int fich, FILE *f) {
  switch (fich) {
    case 1:
      fputs("<!DOCTYPE html>\n", f);
      fputs("<html lang=\"en\">\n", f);
      fputs("<head>\n", f);
      fputs("  <meta charset=\"UTF-8\">\n", f);
      fputs("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n", f);
      fputs("  <link rel=\"stylesheet\" href=\"./css/style.css\">", f);
      fputs("  <title>Document</title>\n", f);
      fputs("</head>\n", f);
      fputs("<body>\n", f);
      fputs("  \n", f);
      fputs("  <script type=\"module\" src=\"./js/main.js\"></script>\n", f);
      fputs("</body>\n", f);
      fputs("</html>\n", f);
  }
}

void creator(int d, char *argv[]) {
  char dir[BUFFER_SIZE];
  char doss[BUFFER_SIZE];
  char *dossier[] = {"css", "js"};

  int i = 0;
  int j = 0;
  switch (d) {
    case 0: doss
    case 1: doss = dossier[0];
      printf("mkdir: %s.\n", doss);
      break;
    case 2: doss = dossier[1];
      printf("mkdir: %s.\n", doss);
      break;
    default:
      printf("Wrong d input.\n");
  } 
   
    while (i < BUFFER_SIZE && argv[1][i] != '\0') {
      dir[i] = argv[1][i];
      i++;
    }
    while (i < BUFFER_SIZE && doss[0][j] != '\0') {
      dir[i] = doss[0][j];
      j++;
      i++;
    }
    dir[i] = '\0';
    printf("%s\n", dir);

    mkdir(dir, 0755);
}
