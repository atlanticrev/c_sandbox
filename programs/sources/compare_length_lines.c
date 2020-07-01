#include <stdio.h>

// Максимальная длинна входной строки
#define MAXLINE 1000

// Прототипы функций
int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) 
{
	int length; // Длинна текущей строки
	int max; // Максимальная длинна строки встретившаяся до этого момента
	char line[MAXLINE]; // Текущая входная строка
	char longest[MAXLINE]; // Самая длинная строка сохраняется здесь

	max = 0;

	// getlines() и заполняет строку символами и считает их кол-во?
	while ((length = getlines(line, MAXLINE)) > 0)
	{
		if (length > max) {
			max = length;
			copy(longest, line);
		}
	}

	if (max > 0) 
	{
		printf("%s", longest);
	}

	return 0;
}

// Считывает строку в string[] и возвращает длину строки
// Изменяет массив напрямую, без создания его копии
int getlines(char string[], int limit)
{
	int c, i;

	for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		string[i] = c;
	}

	if (c == '\n') 
	{
		string[i] = c;
		++i;
	}

	string[i] = '\0';

	return i;
}

// Копирует посимвольно из строки в строку (массивы символов)
void copy(char to[], char from[])
{
	int i;

	i = 0;

	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}