#include <stdio.h>

int main()
{
	long char_counter = 0;

	char_counter = 0;
	while (getchar() != EOF)
		++char_counter;
	printf ("%ld\n", char_counter);
	
	return 0;
}

