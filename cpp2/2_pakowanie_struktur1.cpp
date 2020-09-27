#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct eax {
    int   a_1;      // 4 bajty
    int   a_2;      // 4 bajty
    char  c_1;      // 1 bajt
    int   a_3;      // 4 bajty
    char  c_2;      // 1 bajt   
    bool  b_1;      // 1 bajt 
};

int main()
{    
    system ("clear");       // coby ekran zawsze był czysty :)

    cout << sizeof(eax) << "\n";
}
