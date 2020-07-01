#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

int main(void)
{
	int character, 
	new_line, 
	new_word, 
	new_character, 
	state;

	state = OUT_WORD;
	new_line = new_word = new_character = 0;

	while ((character = getchar()) != EOF) {
		++new_character;

		if (character == '\n')
			++new_line;

		if (character == ' ' || character == '\n' || character == '\t')
			state = OUT_WORD;

		else if (state == OUT_WORD) {
			state = IN_WORD;
			++new_word;
		}

	}

	printf ("\n%d\n%d\n%d\n\n", new_line, new_word, new_character);

	return 0;
}