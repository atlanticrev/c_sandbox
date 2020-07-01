#include <stdio.h>

int main(void)
{
	int caracter;
	// Копирование текстового потока посимвольно
	while ((caracter = getchar()) != EOF) {
		putchar(caracter);
	}

	return 0;
}