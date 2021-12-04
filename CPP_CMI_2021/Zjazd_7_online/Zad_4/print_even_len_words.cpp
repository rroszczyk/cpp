#include <iostream>
#include <fstream>

using namespace std;

bool isEven(string word);

int countWordLen(string word);

int main(int argc, char *argv[])
{
	const char *filename;
	const char *defaultFilename = "input.txt";
	ifstream input;
	string word;

	filename = argc == 2 ? argv[1] : defaultFilename;

	input.open(filename);

	if (!input.is_open())
	{
		cerr << "Cannot open file: " << filename << ".\n";
		exit(-1);
	}

	while (input >> word)
	{
		if (isEven(word))
		{
			cout << word << endl;
		}
	}

	return 0;
}

bool isEven(string word)
{
	int nOfChars = countWordLen(word);
	bool result = (nOfChars % 2 == 0);

	return result;
}

int countWordLen(string word)
{
	int counter = 0;
	int n = word.length();

	for (int i = 0; i < n; i++)
	{
		if ((word.at(i) & 0xC0) != 0x80)
		{
			counter++;
		}
	}
	return counter;
}
