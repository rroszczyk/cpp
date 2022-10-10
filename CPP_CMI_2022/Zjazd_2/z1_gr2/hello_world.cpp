#include <iostream>
#include <iomanip>
#include <cstdio> // dla C (printf), zeby kompilator nie mial pretensji

using namespace std;

int main()
{
    int n = 10000;
    cout << "Hello, World! " << setw(4) << n << "\n";
    cout << "Hello, World! " << setw(4) << n << endl;
    printf("Hello, World! %4d\n", n);
    
    cout << "TEKST " << n << " " << n << " " << n << "\n";
    printf("TEKST %d %d %d\n", n, n, n);
    return 0;
}
