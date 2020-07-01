// Вместо букв при успешной проверке 
// нужно вывести соответствующие символы

#include <stdio.h>

int main(void)
{
	int character;

	while ((character = getchar()) != EOF) {
		if (character == '\t') {
			character = 't';
		}	
		else if (character == '\b') {
			character = 'b';
		}
		else if (character == '\\') {
			character = 's';
		}

		putchar(character);
	}

	return 0;
}