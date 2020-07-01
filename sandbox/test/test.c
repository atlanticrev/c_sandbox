#include <stdio.h>

void print_char_n(char c, int n)
{
  int k;
  for (k = 0; k < n; k++)
  {
    printf("%c", c);
  }
}

void print_string(char const *string)
{
  printf("%s\n", string);
}

int main(int argc, char const *argv[])
{
  // print_char_n('a', 14);
  print_string("hello");
  return 0;
}
