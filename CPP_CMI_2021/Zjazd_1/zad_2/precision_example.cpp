#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "PI = " << setprecision(8) << 3.14159265359 << endl;
	cout << "PI = " << setprecision(8) << M_PI << endl;

	cout.setf(ios::fixed);
	cout << "PI (bez zaokrąglania) = " << setprecision(8) << M_PI << endl;

	cout << "A jaka teraz jest precyzja? Coś długiego po przecinku = " << 3.123456789 << endl;

	printf("PI = %g\n", M_PI);
	printf("PI = %.8g\n", M_PI);

	float factor = pow(10, 7);
	printf("PI = %.8g\n", trunc(M_PI * factor) / factor);
	printf("PI = %f\n", M_PI);

	printf("%10.8g\n", M_PI);
	printf("%11.8g\n", M_PI);
	printf("%12.8g\n", M_PI);

	return 0;
}
