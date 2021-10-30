//g++ 0_hello_world_2.cpp -DPOL
#include <iostream>

#if defined(POL) && defined(FRA)
  #error Please define only one country
#elif !(defined(POL) || defined(FRA))
  #error Please define a country
#endif

#ifdef POL
  #define country "Poland"
  #define capital "Warsaw"
#elif defined(FRA)
  #define country "France"
  #define capital "Paris"
#endif

using namespace std;

int main() {
  system ("clear");       // coby ekran zawsze był czysty :)

  cout << capital << " is the capital of "
       << country << "." << endl;
}