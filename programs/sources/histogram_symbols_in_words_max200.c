#include <stdio.h>

#define MAXWORDS 200

#define IN_WORD 1
#define OUT_WORD 0

int main(void)
{
	int character, 
	state,
	symbols_in_words[MAXWORDS] = {0},
	word_index,
	max_symbols;

	state = OUT_WORD;
	word_index = 0;
	max_symbols = 0;

	printf("\n%s\n\n", "Гистограмма количества символов в словах:");

	while ((character = getchar()) != EOF) 
	{

		// Сюда попадаем, если символ пустой
		if (character == ' ' || character == '\n' || character == '\t')
		{
			// Если мы находились в слове, то установить счетчик слов на следующее
			if (state == IN_WORD)
			{
				word_index++;
			}

			// Выходим из слова
			state = OUT_WORD;
		}

		// Сюда попадаем, если символ не пустой
		else if (state == OUT_WORD) 
		{
			// Входим в слово
			state = IN_WORD;
		}

		// Если мы в слове, то увеличить кол-во символов
		if (state == IN_WORD)
		{
			symbols_in_words[word_index]++;
		}

	}

	// Определяем наибольшее кол-во символов в слове
	// Поиск наибольшего числа в массиве
	for (int i = 0; i < word_index; ++i)
	{
		if (symbols_in_words[i] > max_symbols)
		{
			max_symbols = symbols_in_words[i];
		}
	}

	// Отрисовываем гистограмму горизонтально
	// for (int i = 0; i < word_index; ++i)
	// {
	// 	printf("%4i - ", i + 1);

	// 	for (int j = 0; j < symbols_in_words[i]; ++j)
	// 	{
	// 		printf("#");
	// 	}

	// 	printf("\n");
	// }

	// Отрисовываем гистограмму вертикально
	// Строки
	for (int i = 0; i < max_symbols; ++i)
	{
		// Вывод шкалы кол-ва слов в слове
		printf("%3i ", max_symbols - i);
		// Столбцы
		for (int j = 0; j < word_index; ++j)
		{
			// Определяю, нужно ли рисовать символ в данной позиции
			// Если разница самого большого кол-ва символов и кол-ва их в данном слове
			// меньше либо равна номеру строки (связь разницы и номера строки)
			if (max_symbols - symbols_in_words[j] <= i)
			{
				printf("|");
			}
			else 
			{
				printf(" ");
			}
		}

		printf("\n");
	}

	return 0;
}