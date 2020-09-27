#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

struct ax {
    short h;
    short l;
} sax;

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)

    int y;
    
    int steps = 256 * 1024 * 1024;
    int a[2];

    clock_t start1 = clock();
    for (int i = 0; i < steps; i++) 
    { 
        a[0]++; 
        a[0]++; 
    }
    cout << "Czas wykonywania 0, 0: " << clock() - start1 << "ms\n";

    clock_t start2 = clock();
    for (int i=0; i<steps; i++) 
    { 
        a[0]++; 
        a[1]++; 
    }
    cout << "Czas wykonywania 0, 1: " << clock() - start2 << "ms\n";

    clock_t start3 = clock();
    for (int i = 0; i < steps; i++) 
    { 
        sax.h++; 
        sax.l++; 
    }
    cout << "Czas wykonywania sax++: " << clock() - start3 << "ms\n";

    clock_t start4 = clock();
    for (int i = steps; i >= 0; i--) 
    { 
        sax.l++; 
        sax.h++; 
    }
    cout << "Czas wykonywania sax--: " << clock() - start4 << "ms\n";

     return 0;
}