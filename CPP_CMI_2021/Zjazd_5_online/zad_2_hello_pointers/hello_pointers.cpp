#include <iostream>

using namespace std;

void print_address_wrong(const char *var_name, int variable);

void print_address(const char *var_name, int *variable_addr);

void print_addr(const char *var_name, void *variable_addr);

void func1();

void func2();

void func3();

void func4();

int main(int argc, char *argv[])
{
	int x, *p_x, y;
	/*int x;
	int* p_x;
	int y;*/

	char name[] = "Ola";
	char first_letter = 'O';
	char *p_letter;

	int numbers[] = {1, 4, 6, 8, 10};

	cout << "Hello, pointers!" << endl;

	x = 12;
	y = 3;
	p_letter = name;
	p_letter = &first_letter;

	cout << "Address of \"" << x << "\"\t = " << &x << endl;
	cout << "Address of \"" << y << "\"\t = " << &y << endl;
	cout << "Address of \"" << first_letter << "\"\t = " << (void *)&first_letter << endl;
	cout << "Address of \"" << name << "\"\t = " << &name << endl;

	print_address_wrong("x", x);
	print_address_wrong("y", y);
	print_address("x", &x);

	print_addr("x", &x);
	print_addr("p_letter", &p_letter);

	cout << endl
		 << endl;
	func1();
	cout << endl;
	func3();

	return 0;
}

void print_address_wrong(const char *var_name, int variable)
{
	cout << "Address of " << var_name << "\t = " << &variable << endl;
}

void print_address(const char *var_name, int *variable_addr)
{
	cout << "Address of " << var_name << "\t = " << variable_addr << endl;
}

void print_addr(const char *var_name, void *variable_addr)
{
	cout << "Addr of " << var_name << "\t = " << variable_addr << endl;
}

void func1()
{
	int x1 = 13;
	int y1 = 14;
	int z1;

	int *nums1 = (int *)malloc(sizeof(int) * x1);
	if (nums1 != NULL)
	{
		nums1[0] = 145;
	}

	print_addr("x1", &x1);
	print_addr("y1", &y1);
	print_addr("z1", &z1);
	print_addr("nums1", &nums1);
	print_addr("nums1", &nums1[0]);

	func2();

	//free(nums1);
}

void func2()
{
	int x2 = 13;
	int y2 = 14;
	int z2;

	int *nums2 = (int *)malloc(sizeof(int) * x2);
	if (nums2 != NULL)
	{
		nums2[0] = 145;
	}

	print_addr("x2", &x2);
	print_addr("y2", &y2);
	print_addr("z2", &z2);
	print_addr("nums2", &nums2);
	print_addr("nums2", &nums2[0]);

	free(nums2);
}

void func3()
{
	int x3 = 13;
	int y3 = 14;
	int z3;

	int *nums3 = (int *)malloc(sizeof(int) * x3);
	if (nums3 != NULL)
	{
		nums3[0] = 145;
	}

	print_addr("x3", &x3);
	print_addr("y3", &y3);
	print_addr("z3", &z3);
	print_addr("nums3", &nums3);
	print_addr("nums3", &nums3[0]);

	func4();

	free(nums3);
}

void func4()
{
	int x4 = 13;
	int y4 = 14;
	int z4;

	int *nums4 = (int *)malloc(sizeof(int) * x4);
	if (nums4 != NULL)
	{
		nums4[0] = 145;
	}

	print_addr("x4", &x4);
	print_addr("y4", &y4);
	print_addr("z4", &z4);
	print_addr("nums4", &nums4);
	print_addr("nums4", &nums4[0]);

	free(nums4);
}
