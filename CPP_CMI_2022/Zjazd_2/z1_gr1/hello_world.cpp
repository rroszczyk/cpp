#include <iostream>
#include <iomanip>
#include <cstdio> // dla C (printf), zeby kompilator nie mial pretensji

using namespace std;

int main()
{
    int a = 65536;
    cout << "Hello, World! " << setw(4) << a << endl;
    printf("Hello, World! %4d\n", a);
    return 0;
}
