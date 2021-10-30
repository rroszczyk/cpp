#include <iostream>

using namespace std;

struct S
{
    int32_t total;
    int32_t a, b;
} struct_S;

#pragma pack(push, 1)
struct P
{
    int32_t total;
    int32_t a, b;
} struct_P;
#pragma pack(pop)

struct ExtraS
{
    char c;
    S s;
    char d;
} struct_extra_s;

#pragma pack(push, 1)
struct ExtraP
{
    char c;
    P p;
    char d;
} struct_extra_p;
#pragma pack(pop)

int main() 
{ 
    system ("clear");       // coby ekran zawsze był czysty :)   
    cout << "sizeof(struct_S) = " << sizeof(struct_S) << "\n" ;
    cout << "sizeof(struct_P) = " << sizeof(struct_P) << "\n" ;

    cout << "sizeof(struct_extra_s) = " << sizeof(struct_extra_s) << "\n" ;
    cout << "sizeof(struct_extra_p) = " << sizeof(struct_extra_p) << "\n" ;
} 