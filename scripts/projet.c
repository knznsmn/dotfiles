// Create a fresh project directory

#include <stdio.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

  if (argc < 2)
    printf("\nUsage:\n\n\t%s <path/to/project>\n", argv[0]);
  else {
    
    char *files[] = {"/index.html", "./css/style.css", "./js/main.js"};


    char html[BUFFER_SIZE];
    int i = 0;
    while (i < BUFFER_SIZE && argv[1][i] != '\0') {
      html[i] = argv[1][i];
      i++;
    }
    int j = 0;
    while (i < BUFFER_SIZE && files[0][j] != '\0') {
      html[i] = files[0][j];
      j++;
      i++;
    }
    html[i] = '\0';
    printf("%s\n", html);

    mkdir(argv[1], 0755);

    FILE *f = fopen(html, "w");
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
      fputs("  <script type=\"module\" src=\"./js/main.js\"></script>", f);
      fputs("</body>\n", f);
      fputs("</html>\n", f);
    fclose(f);
  }
}
