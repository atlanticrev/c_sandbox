#include <stdio.h>

int main(void)
{
	int number1 = 100;

	int* number1Pointer = &number1;
	*number1Pointer = 200;
	
	printf("\n%d\n", number1);

	return 0;
}