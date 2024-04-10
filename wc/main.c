#include <stdio.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Requires two arguments.");
    return 1;
  }

  char* filename = argv[2];
  FILE *fp = {0};
  fp = fopen(filename, "r");

  switch (argv[1][1]) {
    case 'c': 
      {
        int bytes = 0;

        while (fgetc(fp) != EOF) ++bytes;

        printf("%d %s", bytes, filename);
      }
    case 'l': 
      {
        int lines = 0;
        char string[1000];

        while (fgets(string, 1000, fp)) ++lines;

        printf("%d %s", lines, filename);
      }
    case 'w': 
      {
        int words = 0;
        char string[1000];

        while (fscanf(fp, "%s", string) != EOF) words++;

        printf("%d %s", words, filename);
      }
    default: break;
  }

  fclose(fp);
  return 0;
}
