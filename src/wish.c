#include <limits.h>
#include "wish.h"

int wish_parse_command(char *command);

int main(int argc, char *argv[])
{
  // These two lines make the macOS C compiler happy.
  // Otherwise, it complains about unused parameters.
  (void)argc;
  (void)argv;
  // int wish_exit;
  char path[PATH_MAX];
  char *home = getenv("HOME");
#ifdef DEBUG
  home = "."; // So that you could place the config into the CWD
#endif
  sprintf(path, "%s/%s", (home ? home : "."), WISH_CONFIG);
  wish_read_config(path, 1);

  // This is just a skeleton for your convenience
  do
  {
    fputs(WISH_DEFAULT_PROMPT, stdout);
    char *line = wish_read_line(stdin);
    wish_exit = wish_parse_command(line);
    if (line)
      free(line);
  } while (wish_exit != 0);

  return EXIT_SUCCESS;
}
