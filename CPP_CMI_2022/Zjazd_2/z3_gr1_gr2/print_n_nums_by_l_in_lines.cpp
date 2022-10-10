#include <iostream>
#include <iomanip>
#include <cstdlib> // dla C (atoi), zeby kompilator nie krzyczal
#include <cstdio>  // dla C (printf), zeby kompilator nie krzyczal

using namespace std;

int main(int argc, char *argv[])
{
    int n = (argc > 1 && atoi(argv[1]) > 0) ? atoi(argv[1]) : 100;
    int l = (argc > 2 && atoi(argv[2]) > 0) ? atoi(argv[2]) : 10;

    cout << "n = " << n << endl;
    cout << "l = " << l << endl;

    for (int i = 0; i < argc; i++)
    {
        // cout << "argv[" << i << "]=" << argv[i] << endl;
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << setw(4) << i << ((i % l == 0) ? "\n" : "");
    }

    cout << "koniec\n";

    return 0;
}
