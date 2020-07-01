#include <stdio.h>

int main(void)
{
	int blanks_counter, 
	tabs_counter, 
	new_lines_counter, 
	character;

	blanks_counter = 0;
	tabs_counter = 0;
	new_lines_counter = 0;
	character = 0;

	while ((character = getchar()) != EOF) {
		if (character == '\n') {
			++new_lines_counter;
		}	
		else if (character == '\t') {
			++tabs_counter;
		}
		else if (character == ' ') {
			++blanks_counter;
		}
	}
			
	printf ("\n%d\n%d\n%d\n\n", blanks_counter, tabs_counter, new_lines_counter);
	
	return 0;
}