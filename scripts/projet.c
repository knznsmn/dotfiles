// Create a fresh project directory

#include <stdio.h>
#include <sys/stat.h>

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

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

  if (argc < 2)
    printf("\nUsage:\n\n\t%s <path/to/project>\n", argv[0]);
  else {
    
    char *files[] = {"/index.html", "./css/style.css", "./js/main.js"};


    char dir[BUFFER_SIZE];
    
    int i = 0;
    int j = 0;
    while (i < BUFFER_SIZE && argv[1][i] != '\0') {
      dir[i] = argv[1][i];
      i++;
    }
    while (i < BUFFER_SIZE && files[0][j] != '\0') {
      dir[i] = files[0][j];
      j++;
      i++;
    }
    dir[i] = '\0';
    printf("%s\n", dir);

    mkdir(argv[1], 0755);

    FILE *f = fopen(dir, "w");
      writer(1, f);
    fclose(f);
  }


}
