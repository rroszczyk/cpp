#include <iostream>

using namespace std;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)
        
    int suma_opadow = 0;
    
    cout << "Jak dużo deszczu spadło: ";
    cin >> suma_opadow;

    if (suma_opadow > 100)
    {
        cout << "Lało jak z cebra" << endl;        
    } else if (suma_opadow > 50) {
        cout << "Padał rzęsisty deszcz" << endl;
    } else if (suma_opadow > 20) {        
        cout << "Padał deszczyk" << endl;        
    } else {
        cout << "Można powiedzieć, że nic nie padało" << endl;        
    }   
   
    return 0;
}