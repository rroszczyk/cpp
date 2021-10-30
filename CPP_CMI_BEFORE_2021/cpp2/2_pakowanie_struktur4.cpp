#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct ax {
    unsigned char   al;
    unsigned char   ah;
};

struct bx {
    unsigned char   bl:4;
    unsigned char   bh:4;
};

struct bb {
    bool    b1:1;
    bool    b2:1;
    bool    b3:1;
    bool    b4:1;
    bool    b5:1;
    bool    b6:1;
    bool    b7:1;
    bool    b8:1;
} BB;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)
    ax ax;
    bx bx;

    unsigned char *liczba;
    unsigned char *cfg = (unsigned char*)&BB;

    liczba = (unsigned char*)&ax;

    *liczba = 110;
    cout << "size of ax: " << sizeof(ax) << "\n";
    cout << "ax: " << bitset<8>(*liczba) << "\n";    
    cout << "ah: " << bitset<4>(ax.ah) << " al: " << bitset<4>(ax.al) << "\n";
    cout << "\n\n\n\n";

    liczba = (unsigned char*)&bx;

    *liczba = 110;
    cout << "size of bx: " << sizeof(bx) << "\n";    
    cout << "bx: " << bitset<8>(*liczba) << "\n";    
    cout << "bh: " << bitset<4>(bx.bh) << " bl: " << bitset<4>(bx.bl) << "\n\n\n";

    cout << "size of BB: " << sizeof(BB) << "\n";     
    BB.b1 = true;
    BB.b5 = true;
    cout << "bx: " << bitset<8>(*cfg) << "\n";        
}
