#include <iostream>

using namespace std;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)

    //int ile = 0;    
    int ile = 4;
    
    do
    {
        cout << "Napis " << ile << endl;
        ile--;
    } while (ile > 0);
   
    return 0;
}