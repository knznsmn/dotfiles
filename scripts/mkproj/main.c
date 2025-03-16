#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void header(FILE *f, char *argv[]);
void writer(int, char *, char *argv[]);
char *fichier(int, char *argv[]);

#define BUFF_SIZE 256
typedef enum Files { HTML, CSS, JS, UTILS } Files;

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("\nUsage:\n\n\t%s <project/name>\n\n", argv[0]);
  }
  else {
    int i = 0;
    char *dir;
    while (i < BUFF_SIZE && argv[1][i] != '\0') {
      i++;
    }
    if (argv[1][i - 1] == 'c' && argv[1][i - 2] == '.') {
      printf("The argument is a .c file\n");
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
      
      i = 0;
      char cmd[BUFF_SIZE];
      snprintf(cmd, BUFF_SIZE, "mkdir %s", argv[1]);
      system(cmd);
      printf("Created the root directory '%s'.\n", argv[1]);
      dir = fichier(HTML, argv);
      writer(HTML, dir, argv);
      
      while (i < (sizeof(dossiers) / sizeof(dossiers[0]))) {
        snprintf(cmd, BUFF_SIZE, "mkdir -p %s/%s", argv[1], dossiers[i]);
        system(cmd);
        printf("Directory '%s' created.\n", dossiers[i]);
        if (i == 0) {
          snprintf(cmd, BUFF_SIZE, "touch %s/%s/style.css", argv[1], dossiers[i]);
          system(cmd);
          dir = fichier(CSS, argv);
          writer(CSS, dir, argv);
          printf("Created the stylesheet.\n");
        }
        else if (i == 1) {
          snprintf(cmd, BUFF_SIZE, "touch %s/%s/main.js", argv[1], dossiers[i]);
          system(cmd);
          dir = fichier(JS, argv);
          writer(JS, dir, argv);
          printf("Created the script file.\n");
        }
        else if (i == 2) {
          snprintf(cmd, BUFF_SIZE, "touch %s/%s/utils.js", argv[1], dossiers[i]);
          system(cmd);
          dir = fichier(UTILS, argv);
          writer(UTILS, dir, argv);
          printf("Created the utils script file.\n");
        }
        i++;
      }
    }
  }
  return 0;
}

void header(FILE *f, char *argv[]) {

  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  int i = 0;
  int w = 55;
  fputs("/", f);
  while (i < w) {
    fputs("*", f);
    i++;
  }
  fputs("\n\n", f);
  fprintf(f, " %-25s %s\n", "Project name:", argv[1]);
  fprintf(f, " %-25s Julius Cinco Cesar\n", "Author:");
  fprintf(f, " %-25s knznsmn@knznsmn.com\n", "");
  fprintf(f, " %-25s @knznsmn\n\n", "");

  char heure[BUFF_SIZE];
  strftime(heure, sizeof(heure), "%B %d, %Y", tm);
  fprintf(f, " %-25s %s\n", "Date created:", heure);
  strftime(heure, sizeof(heure), "%H:%M:%S", tm);
  fprintf(f, " %-25s %s\n\n", "", heure);


  i = 0;
  while (i < w) {
    fputs("*", f);
    i++;
  }
  fputs("/\n\n", f);
}


void writer(int d, char *dirname, char *argv[]) {

  FILE *f = fopen(dirname, "w");

  switch (d) {
    case HTML:
      fputs("<!DOCTYPE html>\n", f);
      fputs("<html lang=\"en\">\n", f);
      fputs("<head>\n", f);
      fputs("  <meta charset=\"UTF-8\">\n", f);
      fputs("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n", f);
      fputs("  <title>Document</title>\n", f);
      fputs("  <link rel=\"stylesheet\" href=\"./css/style.css\">\n", f);
      fputs("</head>\n", f);
      fputs("<body>\n", f);
      fputs("  <header>\n", f);
      fputs("    <h1>Nouveau Projet</h1>\n", f);
      fputs("  </header>\n", f);
      fputs("  <main>\n", f);
      fputs("\n", f);
      fputs("  </main>\n", f);
      fputs("  <footer>\n", f);
      fputs("    <p>\n", f);
      fputs("      <span id=\"ans\"></span>\n", f);
      fputs("      <a href=\"https://www.github.com/knznsmn\">knznsmn.</a> All rights reversed.\n", f);
      fputs("    </p>\n", f);
      fputs("  </footer>\n", f);
      fputs("  <script type=\"module\" src=\"./js/main.js\"></script>\n", f);
      fputs("</body>\n", f);
      fputs("</html>\n", f);
    break;
  case CSS:
      header(f, argv);
      fputs("/* Global resets */\n", f);
      fputs("\n", f);
      fputs("*, *::before, *::after {\n", f);
      fputs("  box-sizing: border-box;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("* {\n", f);
      fputs("  margin: 0;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("body {\n", f);
      fputs("  line-height: 1.5;\n", f);
      fputs("  -webkit-font-smoothing: antialiased;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("img, picture, video, canvas, svg {\n", f);
      fputs("  display: block;\n", f);
      fputs("  max-width: 100%;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("input, button, textarea, select {\n", f);
      fputs("  font: inherit;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("p, h1, h2, h3, h4, h5, h6 {\n", f);
      fputs("  overflow-wrap: break-word;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("p {\n", f);
      fputs("  text-wrap: pretty;\n", f);
      fputs("}\n", f);
      fputs("h1, h2, h3, h4, h5, h6 {\n", f);
      fputs("  text-wrap: balance;\n", f);
      fputs("}\n", f);
      fputs("#root, #__next {\n", f);
      fputs("  isolation: isolate;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("/* General Styling */\n", f);
      fputs("\n", f);
      fputs(":root {\n", f);
      fputs("	/* Hues */\n", f);
      fputs("	--hue-main: rgb(137, 42, 42); \n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("body {\n", f);
      fputs("	width: 100vw;\n", f);
      fputs("	min-height: 100vh;\n", f);
      fputs("	display: flex;\n", f);
      fputs("	flex-direction: column;\n", f);
      fputs("	font-family: Arial, Helvetica, sans-serif;\n", f);
      fputs("	font-size: 16px;\n", f);
      fputs("	--bgh: rgb(238, 255, 253);\n", f);
      fputs("  --hue: rgb(200, 202, 202);\n", f);
      fputs("  --box: .1rem;\n", f);
      fputs("  --spc: 2rem;\n", f);
      fputs("	background:\n", f);
      fputs("		linear-gradient(90deg,\n", f);
      fputs("		var(--bgh) calc(var(--spc) - var(--box)),\n", f);
      fputs("		transparent 1%) center / var(--spc) var(--spc),\n", f);
      fputs("		linear-gradient(var(--bgh) calc(var(--spc) - var(--box)),\n", f);
      fputs("		transparent 1%) center / var(--spc) var(--spc),\n", f);
      fputs("		var(--hue);\n", f);
      fputs("}\n", f);
      fputs("a {\n", f);
      fputs("	text-decoration: none;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("a:link {\n", f);
      fputs("	color: var(--hue-main);\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("a:visited {\n", f);
      fputs("	color:aquamarine;\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("a:focus {\n", f);
      fputs("	filter: invert(1);\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("a:hover {\n", f);
      fputs("	filter: invert(1);\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("a:active {\n", f);
      fputs("	filter: invert(.5);\n", f);
      fputs("}\n", f);
      fputs("\n", f);
      fputs("header {\n", f);
      fputs("	text-align: center;\n", f);
      fputs("}\n", f);
      fputs("main {\n", f);
      fputs("	flex: 1;\n", f);
      fputs("}\n", f);
      fputs("footer {\n", f);
      fputs("	text-align: center;\n", f);
      fputs("	font-size: .85rem;\n", f);
      fputs("}\n", f);
      fputs("footer span::before {\n", f);
      fputs("	display: inline-block;\n", f);
      fputs("	content: '\\00A9';\n", f);
      fputs("	transform: rotate(180deg);\n", f);
      fputs("	margin: 0 .15rem .5rem;\n", f);
      fputs("}\n", f);
    break;
  case JS:
      header(f, argv);
      fputs("// Function Hall\n", f);
      fputs("import { get_current_year } from \"./modules/utils.js\";\n", f);
      fputs("\n", f);
      fputs("// Anchors\n", f);
      fputs("const ans = document.getElementById('ans');\n", f);
      fputs("ans.innerText = get_current_year();\n", f);
      break;
    case UTILS:
      header(f, argv);
      fputs("export function get_current_year() {\n", f);
      fputs("  return new Date().getFullYear();\n", f);
      fputs("}\n", f);
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
    "/js/modules/utils.js",
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
