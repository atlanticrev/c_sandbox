#include <stdio.h>

enum colors 
{
  red, // 0
  orange, // 1
  yellow,
  green,
  blue,
  violet
};

void printNumber()
{
  enum { max_buffer_size = 1024 }; // constant in local scope (int's only)
  printf("%d\n", max_buffer_size);

  enum prices { book = 20, pen = 5 };
  enum prices price_list = pen;

  switch (price_list)
  {
    case book:
      printf("%d\n", book);
      break;
    
    case pen:
      printf("%d\n", pen);
      break;
  }
}

int main(int argc, char const **argv)
{
  // enum colors color = yellow;
  // int anoter_color = red;
  // printf("%d, %d\n", color, anoter_color);  
  printNumber();
  return 0;
}
