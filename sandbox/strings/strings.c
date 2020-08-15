#include <stdio.h>
#include <stdlib.h>

void string50(FILE *f1, FILE *f2)
{
  // Массив для хранения прочитанной строки
  char buffer[51];
  // Читаем строки не более 51 - 1 символов в длинне (+\0)
  while (fgets(buffer, sizeof(buffer), f1))
  {
    int i;
    int new_line_pos = -1;
    // Встречается ли в строке символ '\n'? 
    for (i = 0; i < sizeof(buffer) && buffer[i]; i++)
    {
      if (buffer[i] == '\n')
      {
        // Если мы его находим, запоминаем его индекс и прекращаем искать
        new_line_pos = i;
        break;
      }
    }
    // Если в строке нет символа конца строки, она была обрезана
    if (new_line_pos == -1)
    {
      int c;
      fputc('\n', f2);
      // Передвигаемся в потоке f1 к ближайшему терминальному символу
      while ((c = fgetc(f1)) != EOF && c != '\n')
      {}    
    }
    else
    {
      // Заменяем \n на \0
      buffer[new_line_pos] = '\0';
      fprintf(f2, "[%s]\n", buffer);
    }    
  }
}

int main(int argc, char const **argv)
{
  fputs("hello\n", stdout);

  char string[6];
  // Читает из stdin не более (6 - 1) символов
  fgets(string, 6, stdin);
  printf("%s\n", string);

  return 0;
}
