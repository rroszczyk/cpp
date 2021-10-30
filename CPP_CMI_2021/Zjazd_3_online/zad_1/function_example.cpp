#include <iostream>
#include <iomanip>

using namespace std;

#define MSG_MAX_SIZE 10

void hello_world();
void read_and_print_message();
double sum(double a, double b);

int main(int argc, char *argv[])
{
	double a, b, sum_result, expected;

	hello_world();
	read_and_print_message();

	a = 0.1;
	b = 0.2;

	sum_result = sum(a, b);
	expected = 0.3;

	if (sum_result == expected)
	{
		cout << "The result is equal " << expected << endl;
	}
	else
	{
		cout << "The result is NOT equal " << expected << endl;
	}

	cout << "Sum result: " << setprecision(100) << sum_result << endl;

	return 0;
}

void hello_world()
{
	cout << "Hello, World!\n";
}

void read_and_print_message()
{
	char message[MSG_MAX_SIZE];
	cout << "Please, write yours message here (and press: ENTER):" << endl;
	//cin >> message;
	cin.getline(message, MSG_MAX_SIZE);
	cout << "Yours message: " << message << endl;

	/*
	for( int i = 0; i < MSG_MAX_SIZE; i++ ){
		printf("message[%d] = %c\n", i, message[i]);
	}

	if( message[MSG_MAX_SIZE - 1] == '\0' ){
		cout << "\\0" << endl;
	}else{
		cout << message[MSG_MAX_SIZE - 1] << endl;
	}
	*/
}

double sum(double a, double b)
{
	double result = a + b;
	return result;
}
