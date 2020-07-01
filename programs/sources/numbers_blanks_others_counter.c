#include <stdio.h>

int main()
{
	int character, i, white_spaces, other_characters;
	int digits[10];

	// Первоначальные значения пустых символов и других символов
	white_spaces = other_characters = 0;

	// Заполняем массив вхождений каждой цифры нулями
	for (i = 0; i < 10; ++i)
	{
		digits[i] = 0;
	}

	// Основной цикл программы
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

	printf("digits =");
	for (i = 0; i < 10; ++i)
	{
		printf(" %d", digits[i]);
	}
	printf(" , white_spaces = %d, other_characters = %d\n", white_spaces, other_characters);

	return 0;
}