#include <iostream>
#include <iomanip>
#include <cmath>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main( int argc, char* argv[] ){
	int n = 10;

	for( int i = 1; i <= n; i++ ){
		cout << setw(2);
		for( int j = 1; j <= n; j++ ){
			//cout << i*j << setw(5);
			//printf("%3.d%3s", i*j, "");
			printf("%3d\t", i*j);
		}
		cout << endl;
	}
}
