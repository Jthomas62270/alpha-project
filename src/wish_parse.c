#include <stdio.h>
#include <string.h>
#include "wish.h"

// https://en.wikipedia.org/wiki/Escape_sequences_in_C#Table_of_escape_sequences
char *wish_unquote(char *s)
{
  for (size_t i = 0; i < strlen(s); i++)
  {
    if (s[i] == '\\')
    {
      switch (s[i + 1])
      {
      case 'a':
        s[i] == '\a';
      case 'b':
        s[i] == '\b';
      /*
      case 'e':
        s[i] == '\e';
      */
      case 'n':
        s[i] == '\n';
      case 'r':
        s[i] == '\r';
      case 't':
        s[i] == '\t';
      case 'v':
        s[i] == '\v';
      case '\\':
        s[i] == '\\';
      case '\'':
        s[i] == '\'';
      case '?':
        s[i] == '\?';
      }
    }
  }
  return s; // MODIFY!
}

// Do not modify this function
void yyerror(const char *s)
{
  fprintf(stderr, "Parse error: %s\n", s);
}

char *wish_safe_getenv(char *s)
{
  return s;
}
