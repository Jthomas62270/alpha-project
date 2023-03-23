#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "wish.h"

int wish_exit = 0;

static void refuse_to_die()
{
  fputs("Type exit to exit the shell.\n", stderr);
}

static void prevent_interruption()
{
  fputs("SYSTEM GHOST: Hi, I am `prevent_interruption()`.\nSYSTEM GHOST: When I am implemented, I will install a signal handler,\nSYSTEM GHOST: and you won't be able to use Ctrl+C anymore :P\n", stderr);

  struct sigaction sa;

  sa.sa_handler = refuse_to_die;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
#
  if (sigaction(SIGINT, &sa, NULL) == -1)
  {
    fputs("Error establishing signal\n", stderr);
  }
}

int main(int argc, char *argv[])
{
  // These two lines make the macOS C compiler happy.
  // Otherwise, it complains about unused parameters.
  (void)argc;
  (void)argv;

  char path[PATH_MAX];
  char *home = getenv("HOME");
#ifdef DEBUG
  home = "."; // So that you could place the config into the CWD
#endif
  sprintf(path, "%s/%s", (home ? home : "."), WISH_CONFIG);
  wish_read_config(path, 1);

  prevent_interruption();
  while (!wish_exit)
  {
    fputs(WISH_DEFAULT_PROMPT, stdout);
    char *line = wish_read_line(stdin);
    if (line)
    {
      wish_parse_command(line);
      free(line);
    }
  }

  return EXIT_SUCCESS;
}
/*
char *super_strdup(const char *s)
{
  // Must be implemented
  fputs("\nSYSTEM GHOST: did you just call unimplemented `super_strdup`?\n",
        stderr);
  return NULL;
}

void *super_malloc(size_t size)
{
  // Must be implemented
  fputs("\nSYSTEM GHOST: did you just call unimplemented `super_malloc`?\n",
        stderr);
  return NULL;
}

void *super_realloc(void *ptr, size_t size)
{
  // Must be implemented
  fputs("\nSYSTEM GHOST: did you just call unimplemented `realloc`?\n",
        stderr);
  return NULL;
}
*/
