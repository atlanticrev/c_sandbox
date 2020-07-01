#include <stdio.h>

int main(void)
{
	int expression_value_one, 
	expression_value_two, 
	end_of_file_value;

	expression_value_one = (getchar() != EOF);
	expression_value_two = !(getchar() != EOF);
	end_of_file_value = EOF;
	printf("\n%d\n%d\n%d\n", expression_value_one, expression_value_two, end_of_file_value);

	return 0;
}