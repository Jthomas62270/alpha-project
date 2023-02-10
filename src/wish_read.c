#include "wish.h"
#include <string.h>
#include <ctype.h>

char *wish_read_line(FILE *in)
{

  if (in == NULL)
  {
    perror("No file is present...");
    return NULL;
  }

  // declaration
  char *buff = NULL;
  // char *line[WISH_MAX_INPUT];
  size_t len = WISH_MAX_INPUT;
  size_t buff_used;

  // readline and save it to buffer
  // param: destination, length of the input, file to stream
  if ((buff_used = getline(&buff, &len, in)) != 1)
  {
    if (buff_used == 0)
    {
      perror("No line entered...\n");
      return NULL;
    }

    if (buff_used > WISH_MAX_INPUT)
    {
      fprintf(stderr, "wish : line too long");
      free(buff);
      return NULL;
    }
    buff[buff_used - 1] = '\0';
  }
  printf("%s\n", buff);
  // free(buff);
  return buff;
}

int wish_read_config(char *fname, int ok_if_missing)
{

  if ((ok_if_missing == 0) && (fname != NULL))
  {
    FILE *in = fopen(fname, "r");
    char *line = wish_read_line(in);
    fclose(in);
  }
  else if ((ok_if_missing == 0) && (fname == NULL))
  {
    perror("File not found...\n");
    return 1;
  }

  return 0;
}
