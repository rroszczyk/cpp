#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] ){
	string filename = "liczby.txt";
	ifstream inputFile(filename);
	string line;
	int n = 0;

	if( !inputFile.is_open() ){
		cout << "Nie można otworzyć pliku \"" << filename << "\"!\n";
		return -1;
	}

	while (!inputFile.eof()){
		getline(inputFile, line);
		n++;
	}

	cout << "Wczytano " << n << " liczb.\n";

	return 0;
}
