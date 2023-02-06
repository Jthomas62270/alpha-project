#include "wish.h"

int main(int argc, char *argv[])
{
  // These two lines make the macOS C compiler happy.
  // Otherwise, it complains about unused parameters.
  argc = 0;
  argv = NULL;
  
  // This is just a skeleton for your convenience
  printf(WISH_DEFAULT_PROMPT); 
  wish_read_line(stdin);
  /*
  char *file = getenv("$HOME"); 
  wish_read_config(file, 0); 
  */
  wish_read_config("wish.config", 1);
  
  return EXIT_SUCCESS;
}
