#include <iostream>

using namespace std;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)

    int liczba;

    cout << "Podaj liczbę: ";
    cin >> liczba;

    cout << "Odliczam od 1 do " << liczba << endl;
    for (int i = 0; i < liczba; i++)
    {
        cout << i + 1;
        if (i != liczba - 1) cout << "...";
    }
    cout << endl;


    return 0;
}