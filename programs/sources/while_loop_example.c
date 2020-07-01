#include <stdio.h>

#define LIMIT 200

void main(void)
{
	int i = 0;

	while (i < LIMIT - 1)
	{
		if ((c = getchar()) != '\n')
		{
			if (c != EOF)
			{
				s[i] = c;
			}
		}

		++i;
	}

	return;
}
