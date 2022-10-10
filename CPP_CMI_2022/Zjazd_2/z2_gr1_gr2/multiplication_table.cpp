#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 10;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    return 0;
}
