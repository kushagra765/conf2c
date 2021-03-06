#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int conf2c(const char *confpath);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("conf2c: No config filepath given. Checking the current dir for it..\n");
    if (access(".config", F_OK) == 0) {
       int ret = conf2c(".config");
       return ret;
    } else {
       printf("conf2c: error: No '.config' given\n");
       return -1;
    }
  }

  const char *confpath = argv[1];
  conf2c(confpath);
}

int conf2c(const char *confpath) {
  FILE *conf_p, *chdr_p;
  char line[256];

  conf_p = fopen(confpath, "r");
  if (!conf_p) {
     printf("conf2c: error: '%s' doesn't exist\n", conf_p);
     return -1;
  }
  chdr_p = fopen("config.h", "w");

  fprintf(chdr_p, "#ifndef _CONFIG_H\n#define _CONFIG_H\n\n");

  while (fgets(line, sizeof(line), conf_p)) {
     /* Ignore lines starting with '#' */
      if (line[0] == '#') {
         continue;
      }

      /* Check for '='. Note: config value should be less than 50. */
      for (int i = 0; i < 50; i++) {
           if (line[i] == '=') {
              /* Save the config option */
              char *confopt = line[i+1];
              /* Remove the equals sign, the config option and
               * the newline character from 'line'.
               */
              line[i] = ' ';
              line[i+1] = ' ';
              line[i+2] = ' ';
              /* Now write the config value and the option */
              fprintf(chdr_p, "#define %s ", line);
              fprintf(chdr_p, "'%s'\n", &confopt);
           } else {
              continue;
           }
      }
  }

  fprintf(chdr_p, "\n#endif //_CONFIG_H");
  fclose(chdr_p);
  fclose(conf_p);
  return 0;
}
