#include <iostream>

using namespace std;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)

    cout << "size of bool \t\t" << sizeof(bool) << "\n\n";

    cout << "size of char \t\t" << sizeof(char) << "\n";
    cout << "size of short \t\t" << sizeof(short) << "\n";
    cout << "size of int \t\t" << sizeof(int) << "\n";
    cout << "size of long \t\t" << sizeof(long) << "\n\n";

    cout << "size of unsigned char \t" << sizeof(unsigned char) << "\n";
    cout << "size of unsigned short \t" << sizeof(unsigned short) << "\n";
    cout << "size of unsigned long \t" << sizeof(unsigned long) << "\n\n";

    cout << "size of float \t\t" << sizeof(float) << "\n";
    cout << "size of double \t\t" << sizeof(double) << "\n";
    cout << "size of long double \t" << sizeof(long double) << "\n\n";
}
