#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void memory_allocation()
{
  double *k;
  int i;
  k = malloc(10 * sizeof(double));
    
  for (i = 0; i < 10; i++) 
  {
      k[i] = sin((2 * M_PI / 360.0) * (double)i * 10);
  }
    
  for (i = 0; i < 10; i++) 
  {
       printf("%.2f\n", k[i]);
  }

  free(k);
}

int main(int argc, char *argv[])
{
  memory_allocation();
  return 0;
}