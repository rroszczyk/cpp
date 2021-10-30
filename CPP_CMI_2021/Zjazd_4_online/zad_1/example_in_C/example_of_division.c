#include <stdio.h>
#include <stdlib.h>

typedef struct div_result_s
{
	int quotient;
	int remainder;
} div_result;

div_result divide(int dividend, int divider);
void print(div_result result);

int main(int argc, char *argv[])
{
	int first_num = argc > 1 ? atoi(argv[1]) : 10;
	int second_num = argc > 2 ? atoi(argv[2]) : 7;

	div_result result = divide(first_num, second_num);
	print(result);

	return 0;
}

div_result divide(int dividend, int divider)
{
	if (divider == 0)
	{
		fprintf(stderr, "Cannot divide by 0!");
		exit(-1);
	}

	div_result result;

	result.quotient = dividend / divider;
	result.remainder = dividend % divider;

	if (result.remainder < 0)
	{
		result.quotient += result.quotient > 0 ? 1 : -1;
		result.remainder = dividend - (result.quotient * divider);
	}

	return result;
}

void print(div_result result)
{
	printf("quotient: %d | remainder: %d\n", result.quotient, result.remainder);
}
