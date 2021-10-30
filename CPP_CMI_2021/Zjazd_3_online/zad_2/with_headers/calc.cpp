#include <iostream>
#include <cmath>
#include "calc.hpp"

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
