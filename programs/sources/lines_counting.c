#include <stdio.h>

int main()
{
	int lines_counter, character = 0;

	lines_counter = 0;
	while ((character = getchar()) != EOF) {
		if (character == '\n') {
			++lines_counter;
		}
	}
	printf ("%ld\n", lines_counter);
	
	return 0;
}