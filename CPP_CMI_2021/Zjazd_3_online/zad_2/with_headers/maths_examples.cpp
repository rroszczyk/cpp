#include <iostream>
#include <cmath>
#include "calc.hpp"

using namespace std;

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
