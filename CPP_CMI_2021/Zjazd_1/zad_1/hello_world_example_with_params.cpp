#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Hello, World!" << std::endl;

	for (int i = 0; i < argc; i++)
	{
		std::cout << "argv[" << i << "]=" << argv[i] << std::endl;
	}

	return 0;
}
