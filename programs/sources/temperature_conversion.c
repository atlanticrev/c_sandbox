#include <stdio.h>

float fahrenheit_to_celsius(int fahrenheit);

void main(void)
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr += 20)
	{
		printf("%3d %6.1f\n", fahr, fahrenheit_to_celsius(fahr));
	}
}

float fahrenheit_to_celsius(int fahrenheit)
{
	return (5.0 / 9.0) * (fahrenheit - 32);
}