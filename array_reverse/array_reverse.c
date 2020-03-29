#include <stdio.h>

int string_length(const char *string)
{
  int i;
  for (i = 0; string[i]; i++)
  {}
  return i;
}

int main(int argc, char *argv[])
{
  int i;
  int j;
  char *string = argv[1];
  int len = string_length(string);
  for (i = 0, j = len - 1; i < j; i++, j--)
  {
    char tmp;
    tmp = string[j];
    string[j] = string[i];
    string[i] = tmp;
  }
  printf("%s\n", string);
  return 0;
}
