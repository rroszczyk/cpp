#include <iostream>
#include <string>
#include <przyklad.hpp>

using namespace std;

#define NAME_QUESTION "What is your name?"
#define SURNAME_QUESTION "What is your surname?"

// #define drugi_przyklad 
// #undef drugi_przyklad

#if defined drugi_przyklad
#define DIM 256
#endif

int main()
{
  string name;
  char surname[10];

  system ("clear");       // coby ekran zawsze był czysty :)

  cout << NAME_QUESTION << " ";
  getline(cin, name);
  cout << "Hello, " << name << "!\n";

  cout << SURNAME_QUESTION << " ";  
  cin.getline(surname, sizeof(surname));
  cout << "Hello, " << name << " " << surname << "!\n";  

#if defined drugi_przyklad
  int k = DIM;
  int doubled_k = 2 * DIM; 

  cout << "k: " << k << "\n";
  cout << "doubled_k: " << doubled_k << "\n";
#else
  cout << "tym razem tylko jeden przykład\n";
#endif  
}

