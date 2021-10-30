#include <iostream>
#include <cmath>

using namespace std;

double add(double term_a, double term_b);
double subtract(double minued, double subtrahend);
double multiply(double multiplier, double multiplicand);
double division(double dividend, double divisor);
double exponents(double base, double exponent);
double square_root(double radicand);
void print_result(char symbol, double a, double b, double result);

int main(int argc, char *argv[])
{
	double a, b, result, root_degree;

	a = 2;
	b = 3;
	root_degree = 2;

	result = add(a, b);
	print_result('+', a, b, result);

	result = subtract(a, b);
	print_result('-', a, b, result);

	result = multiply(a, b);
	print_result('*', a, b, result);

	result = division(a, b);
	print_result('/', a, b, result);

	result = exponents(a, b);
	print_result('^', a, b, result);

	result = square_root(b);
	print_result('r', root_degree, b, result);

	return 0;
}

double add(double term_a, double term_b)
{
	double sum = term_a + term_b;

	return sum;
}

double subtract(double minued, double subtrahend)
{
	double difference = minued - subtrahend;

	return difference;
}

double multiply(double multiplier, double multiplicand)
{
	double product = multiplier * multiplicand;

	return product;
}

double division(double dividend, double divisor)
{
	double quotient = dividend / divisor;

	return quotient;
}

double exponents(double base, double exponent)
{
	double power = pow(base, exponent);

	return power;
}

double square_root(double radicand)
{
	double root = sqrt(radicand);

	return root;
}

void print_result(char symbol, double a, double b, double result)
{
	//cout << "Result of " << "\"" << a << symbol << b << "\"" << "=" << result << endl;
	printf("Result of \"%g %c %g\" = %g\n", a, symbol, b, result);
}
