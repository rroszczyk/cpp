#include <iostream>
#include <fstream>

using namespace std;

bool isWhitespace(char sign);

int main(int argc, char *argv[])
{

	const char *filename;
	const char *defaultFilename = "input.txt";
	ifstream input;
	char sign;
	int counter = 0;

	filename = argc == 2 ? argv[1] : defaultFilename;

	input.open(filename);

	if (!input.is_open())
	{
		cerr << "Cannot open file: " << filename << ".\n";
		exit(-1);
	}

	while (input.good())
	{
		sign = input.get();
		if (isWhitespace(sign))
		{
			counter++;
		}
	}

	input.close();

	printf("Count %d signs.\n", counter);

	return 0;
}

bool isWhitespace(char sign)
{
	return sign == ' ' || sign == '\n' || sign == '\0' || sign == '\t';
}
