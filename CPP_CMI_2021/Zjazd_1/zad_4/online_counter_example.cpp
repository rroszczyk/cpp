#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main(int argc, char *argv[])
{

	for (int i = 0; i < 5; i++)
	{
		cout << "\ri = " << i << " | ";
		cout.flush();
		/*printf("\ri = %d | ", i);
		fflush(stdout);*/
		sleep(1);
	}
	printf("\n");

	return 0;
}
