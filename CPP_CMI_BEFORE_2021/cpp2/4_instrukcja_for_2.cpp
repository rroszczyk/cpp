#include <iostream>

using namespace std;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)

    int liczba;

    cout << "Podaj liczbę: ";
    cin >> liczba;

    cout << "Odliczam od " << liczba << " do 1" << endl;
    for (int i = liczba; i > 0; i--) {
        if ((i > 100) && (i % 10 == 0)) {
            cout << i;
            if (i != 1) cout << "..."; 
        } else if ((i <= 100) && (i > 10) && (i % 5 == 0)) {
            cout << i;
            if (i != 1) cout << "..."; 
        } else if (i <= 10) {
            cout << i;
            if (i != 1) cout << "..."; 
        }
    }
    cout << endl;

    return 0;
}