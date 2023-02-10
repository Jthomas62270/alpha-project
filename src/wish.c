#include "wish.h"

int main()
{
  // These two lines make the macOS C compiler happy.
  // Otherwise, it complains about unused parameters.

  // This is just a skeleton for your convenience
  printf(WISH_DEFAULT_PROMPT);
  wish_read_line(stdin);
  wish_read_config("wish.config", 0);

  return EXIT_SUCCESS;
}
