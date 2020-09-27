#include <iostream>

using namespace std;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)
        
    bool a = true;
    bool b = false;
    
    cout << "!(a && b) = !a || !b -> " << !(a && b) << " : " << (!a || !b) << endl;
    cout << "!(a || b) = !a && !b -> " << !(a || b) << " : " << (!a && !b) << endl;    
   
    return 0;
}