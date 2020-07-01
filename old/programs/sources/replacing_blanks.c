#include <stdio.h>

/*
* Программа не учитывает поток из одник пробельных символов
*/

#define IN 1
#define OUT 0

int main(void)
{
	int character, 
	string_of_blanks;

	string_of_blanks = OUT;

	while ((character = getchar()) != EOF) {

		if (character == ' ') 
		{
			if (string_of_blanks == OUT) 
			{
				string_of_blanks = IN;
			}
		} 

		else 
		{
			// Печатать ' ' только при смене состояния
			if (string_of_blanks == IN) 
			{
				string_of_blanks = OUT;
				putchar(' ');
			}

			putchar(character);
		}
	}
	
	return 0;
}