/*
* Подсчет кол-ва каждой цифры, пробелов и тп.
*/

#include <stdio.h>

main()
{
	int character,
	i,
	white_spaces,
	other_characters;

	int digits[10];

	white_spaces = other_characters = 0;

	// Заполнение массива нулями
	for (i = 0; i < 10; ++i)
	{
		digits[i] = 0;
	}

	// Основной цикл считывания символов
	while ((character = getchar()) != EOF)
	{
		if (character >= '0' && character <= '9')
		{
			++digits[character - '0'];
		} 

		else if (character == ' ' || character == '\n' || character == '\t')
		{
			++white_spaces;
		}

		else 
		{
			++other_characters;
		}
	}

	printf("digits = ");
	for (i = 0; i < 10; ++i)
	{
		printf(" %d", digits[i]);
	}
	printf(", white spaces = %d, other = %d\n", white_spaces, other_characters);
}