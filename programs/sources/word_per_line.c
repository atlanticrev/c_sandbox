#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

int main(void)
{
	int character; 

	while ((character = getchar()) != EOF) {

		if (character == ' ' || character == '\n' || character == '\t') {
			putchar('\n');
		}

		putchar(character);
	}
	
	return 0;
}