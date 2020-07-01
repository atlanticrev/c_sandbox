#include <stdio.h>

// Объявление прототипа функции
int power(int base, int exponent);

int main(void)
{
	int i;

	for (int i = 0; i < 10; ++i)
	{
		printf("%d %d %d\n", i, power(2, i), power(-3, i) );
	}

	return 0;
}

int power(int base, int n)
{
	int i, result;

	result = 1;

	for (int i = 0; i < n; ++i)
	{
		result *= base;
	}

	return result;
}

/*
Другая верия подпрограммы power

int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n)
	{
		p *= base;
	}

	return p;
}
*/