#include <stdio.h>
#include <string.h>
#include "wish.h"

// https://en.wikipedia.org/wiki/Escape_sequences_in_C#Table_of_escape_sequences
char *wish_unquote(char *s)
{
  for (size_t i = 0; i < strlen(s); i++)
  {
    // DZ: 1 What if the symbol after \ is something else?
    // DZ: 2 You replace two characters with one; must close the gap
    // DZ:   by shifting the rest of the string to the left
    if (s[i] == '\\')
    {
      switch (s[i + 1])
      {
      case 'a':
        s[i] == '\a'; // DZ: This is comparison, not assignment
	break; // DZ: read about the switch statement!
      case 'b':
        s[i] == '\b'; // DZ: This is comparison, not assignment
	break; // DZ
      /*
      case 'e':
        s[i] == '\e';
      */
      case 'n':
        s[i] == '\n'; // DZ: This is comparison, not assignment
	break; // DZ
      case 'r':
        s[i] == '\r'; // DZ: This is comparison, not assignment
	break; // DZ
      case 't':
        s[i] == '\t'; // DZ: This is comparison, not assignment
	break; // DZ
      case 'v':
        s[i] == '\v'; // DZ: This is comparison, not assignment
	break; // DZ
      case '\\':
        s[i] == '\\'; // DZ: This is comparison, not assignment
	break; // DZ
      case '\'':
        s[i] == '\''; // DZ: This is comparison, not assignment
	break; // DZ
      case '?':
        s[i] == '\?'; // DZ: This is comparison, not assignment
	break; // DZ
      }
    }
  }
  printf("%s\n",s);
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
