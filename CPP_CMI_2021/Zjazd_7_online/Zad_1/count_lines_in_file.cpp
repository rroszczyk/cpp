#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	/////////////////////////////////////////////
	// C version:
	/*
	const char *defaultFilename = "input.txt";
	const char *filename;
	FILE* fp;
	char* line = NULL;
	size_t len;
	int counter = 0;
	
	filename = argc == 2 ? argv[1] : defaultFilename;

	if( (fp = fopen(filename, "r")) == NULL ){
		cerr << "Cannot open file" << filename << ".\n";
		exit(-1);
	}

	while( getline(&line, &len, fp) != -1 ){
		printf("Line: %s", line);
		counter++;
	}

	fclose(fp);
	*/

	/////////////////////////////////////////////
	// C++ version

	const char *defaultFilename = "input.txt";
	const char *filename;
	ifstream input;
	string line;
	int counter = 0;

	filename = argc == 2 ? argv[1] : defaultFilename;

	input.open(filename);

	if (!input.is_open())
	{
		cerr << "Cannot open file: " << filename << ".\n";
		exit(-1);
	}

	while (getline(input, line))
	{
		cout << line << "\n";
		counter++;
	}

	input.close();

	printf("Counter = %d\n", counter);

	return 0;
}
