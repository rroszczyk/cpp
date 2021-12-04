#include <iostream>
#include <fstream>

using namespace std;

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
		cerr << "Cannot read file: " << filename << "\n";
		exit(-1);
	}

	cout << "hex(128)" << std::hex << 128 << endl;
	cout << "hex(192)" << std::hex << 192 << endl;

	while (input >> sign)
	{
		if ((sign & 0xC0) != 0x80)
		{
			counter++;
		}
	}

	input.close();

	printf("Count %d signs.\n", counter);

	return 0;
}
