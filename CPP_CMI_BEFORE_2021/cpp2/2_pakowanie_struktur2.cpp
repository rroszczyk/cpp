#include <iostream>

using namespace std;


// Alignment requirements 
// (typical 32 bit machine) 
  
// char         1 byte 
// short int    2 bytes 
// int          4 bytes 
// double       8 bytes 
  
// structure A 
typedef struct structa_tag 
{ 
   char        c;   // 1 byte
   short int   s;   // 2 bytes 
} structa_t; 
  
// structure B 
typedef struct structb_tag 
{ 
   short int   s;   // 2 bytes
   char        c;   // 1 byte
   int         i;   // 4 bytes
} structb_t; 
  
// structure C 
typedef struct structc_tag 
{ 
   char        c;   // 1 byte
   double      d;   // 8 bytes
   int         s;   // 4 bytes
} structc_t; 
  
// structure D 
typedef struct structd_tag 
{ 
   double      d;   // 8 bytes
   int         s;   // 5 bytes
   char        c;   // 1 byte
} structd_t; 
  
int main() 
{ 
   system ("clear");       // coby ekran zawsze był czysty :)    
   cout << "sizeof(structa_t) = " << sizeof(structa_t) << "\n" ;
   cout << "sizeof(structb_t) = " << sizeof(structb_t) << "\n" ;
   cout << "sizeof(structc_t) = " << sizeof(structc_t) << "\n" ;
   cout << "sizeof(structd_t) = " << sizeof(structd_t) << "\n" ;         
} 