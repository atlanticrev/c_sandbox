#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

void ten_strings_to_stdout(int argc, char const **argv)
{
  FILE *from, *to;
  int c, lines_count;

  if (argc < 3)
  {
    fprintf(stderr, "Too few arguments\n");
    exit(1);
  }

  from = fopen(argv[1], "r");
  if (!from)
  {
    perror(argv[1]);
    exit(2);
  }

  to = fopen(argv[2], "w");
  if (!to)
  {
    perror(argv[2]);
    exit(3);
  }

  lines_count = 1;
  while (lines_count <= 10 && (c = fgetc(from)) != EOF)
  {
    fputc(c, to);
    if (c == '\n')
    {
      lines_count++;
    }
  }
}

void int_file_sum(FILE *file, int *sum, int *count)
{
  int n;
  *count = 0;
  *sum = 0;

  while (fscanf(file, "%d", &n) == 1)
  {
    *sum += n;
    (*count)++;
  }
  
}

void print_stdin_to_stdout(const char *file_name)
{
  char c;

  // Open readable stream
  FILE *file = fopen(file_name, "r");
  if (!file) 
  {
    perror(file_name);
    exit(1);
  }
  printf("file %s opened:\n", file_name);

  // Print characters to stdout
  while ((c = fgetc(file)) != EOF)
  {
    printf("character is: %c\n", c);
  }
  
  fclose(file);

  printf("file %s closed:\n", file_name); 
}

// Print Sin, Cos tables [0, 360] degrees
void print_sin_cos(const char *file_name)
{
  FILE *file;
  int degrees;

  file = fopen(file_name, "w");

  if (!file) 
  {
    perror(file_name);
    exit(1);
  }

  for (degrees = 0; degrees <= 360; degrees++)
  {
    double radians = (double)degrees * M_PI / 180.0;
    double s = sin(radians);
    double c = cos(radians);
    fprintf(file, "%03d % 7.5f % 7.5f\n", degrees, s, c);
  }
  fclose(file);
}

int main(int argc, char const **argv)
{
  // ten_strings_to_stdout(argc, argv);

  // print_stdin_to_stdout(argv[1]);

  // print_sin_cos("sincos.txt");

  FILE *file;
  file = fopen(argv[1], "r");
  int sum;
  int count;

  int_file_sum(file, &sum, &count);
  fprintf(stdout, "%d %d\n", sum, count);

  fclose(file);

  return 0;
}
