#include <iostream>

using namespace std;

#define JEDEN 1
#define DWA 2
#define TRZY 3

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)

    int liczba;

    cout << "Podaj liczbę: ";
    cin >> liczba;
    
    switch (liczba) 
    {
        case DWA: 
            //char zmienna = 'x';
            cout << "dwa" << endl;
            break; 
        case JEDEN: 
            cout << "jeden" << endl;
            break;
        case TRZY:
            cout << "trzy" << endl;
            break;
        default:
            cout << "ja potrafię liczyć tylko do 3 :(" << endl;
    }
    return 0;
}