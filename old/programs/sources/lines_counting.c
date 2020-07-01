#include <stdio.h>

/*
*	Программа не всегда корректно определяет кол-во строк
*/

int main()
{
	int lines_counter, 
	character;

	lines_counter = 0;

	while ((character = getchar()) != EOF) 
	{
		if (character == '\n') 
		{
			++lines_counter;
		}
	}
	printf ("%d\n", lines_counter);
	
	return 0;
}