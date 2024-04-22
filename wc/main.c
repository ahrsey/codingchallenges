#include <stdio.h>

void count_bytes(FILE* fp, int* b) {
  int bytes = 0;
  while (fgetc(fp) != EOF) ++bytes;
  *b = bytes;
}

void count_lines(FILE* fp, int* l) {
  int lines = 0;
  char string[1000];
  while (fgets(string, 1000, fp)) ++lines;
  *l = lines;
}

void count_words(FILE* fp, int* w) {
  int words = 0;
  char string[1000];
  while (fscanf(fp, "%s", string) != EOF) ++words;
  *w = words;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Requires two arguments.");
    return 1;
  }

  char* filename = argv[2];
  FILE *fp = {0};
  fp = fopen(filename, "r");
  int bytes = 0;
  int lines = 0;
  int words = 0;

  switch (argv[1][1]) {
    case 'c': 
      {
        count_bytes(fp, &bytes);
        printf("%d %s", bytes, filename);
        break;
      }
    case 'l': 
      {
        count_lines(fp, &lines);
        printf("%d %s", lines, filename);
        break;
      }
    case 'w': 
      {
        count_words(fp, &words);
        printf("%d %s", words, filename);
        break;
      }
    default: break;
  }

  fclose(fp);
  return 0;
}
