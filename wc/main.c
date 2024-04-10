#include <stdio.h>
#include <sys/stat.h>

// char *fgets(char s[restrict .size], int size, FILE *restrict stream);
// https://codingchallenges.fyi/challenges/challenge-wc#help-others-by-sharing-your-solutions
int main(int argc, char** argv) {
  for (int i = 0; i < argc; ++i) {
    switch (argv[i][1]) {
      case 'c': 
        {
          struct stat sb = {0};
          char* filename = argv[i+1];
          if (stat(filename, &sb) == -1) {
            perror("stat");
            return 1;
          }
          printf("%lld %s\n", (long long)sb.st_size, filename);
        }
      default: break;
    }
  }

  return 0;
}
