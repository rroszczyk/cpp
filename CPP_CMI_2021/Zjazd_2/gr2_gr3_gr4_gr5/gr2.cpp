#include <iostream>

using namespace std;

void print_tab(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "tab[" << i << "]=" << tab[i] << endl;
        cout << i << endl;
    }
}

int main(int argc, char *argv[])
{
    int m = 6;
    int tab[m];
    for (int i = 0; i < m; i++)
    {
        tab[i] = i * 2;
    }
    print_tab(tab, m);

    int x = 12;
    int y = 6;
    cout << "&x=" << &x << endl;
    cout << "&y=" << &y << endl;

    int *wsk;
    wsk = &x;
    cout << "wsk=" << wsk << endl;
    cout << "*wsk=" << *wsk << endl;

    x = 73;
    cout << "x = " << x << endl;
    cout << "*wsk = " << *wsk << endl;
    x = 74;
    if (x == 73)
    {
        cout << ">>> x = 73" << endl;
    }
    else
    {
        cout << ">>> x != 73" << endl;
    }
}
