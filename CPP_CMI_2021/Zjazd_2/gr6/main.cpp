#include <iostream>

using namespace std;

void swap(int &first, int &second);

int main(int argc, char *argv[])
{
    std::cout << "Hello\n";

    int a = 6;
    int b = 12;

    cout << "a = " << a << " | b = " << b << endl;

    int tmp_a = a;
    a = b;
    b = tmp_a;

    cout << "a = " << a << " | b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << " | b = " << b << endl;

    return 0;
}

void swap(int &first, int &second)
{
    int tmp_first = first;
    first = second;
    second = tmp_first;
}
