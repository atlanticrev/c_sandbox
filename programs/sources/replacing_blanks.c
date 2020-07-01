#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int character, 
	sting_of_blanks;

	sting_of_blanks = OUT;

	while ((character = getchar()) != EOF) {

		if (character == ' ') 
		{
			if (sting_of_blanks == OUT) 
			{
				sting_of_blanks = IN;
			}
		} 

		else 
		{
			// Печатать ' ' только при смене состояния
			if (sting_of_blanks == IN) 
			{
				sting_of_blanks = OUT;
				putchar(' ');
			}

			putchar(character);
		}

	}
	return 0;
}