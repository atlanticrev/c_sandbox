#include <stdio.h>

#define YES 1
#define NO 0

int main(void)
{
	int character,
	should_create_new_line,
	in_word; 

	in_word = NO;
	should_create_new_line = NO;

	while ((character = getchar()) != EOF) 
	{
		if (character == ' ' || character == '\n' || character == '\t') 
		{
			in_word = NO;

			if (should_create_new_line == YES)
			{
				putchar('\n');
				should_create_new_line = NO;
			}
		}

		// Если "непустой" символ встретился первый раз после "пустого"
		else if (in_word == NO) 
		{
			in_word = YES;
			should_create_new_line = YES;
		}

		// Если символ "непустой", то печатаем его
		if (character != ' ' && character != '\n' && character != '\t')
		{
			putchar(character);
		}
	}
	
	return 0;
}