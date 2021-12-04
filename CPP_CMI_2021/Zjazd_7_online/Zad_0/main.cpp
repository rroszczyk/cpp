//
//  main.cpp
//  tabn
//
//  Created by Grzegorz Gołębiewski on 20/11/2021.
//

#include <iostream>

int main(int argc, const char *argv[])
{
    int myTab[10];
    int tabSize = 5;
    myTab[0] = 0;

    while (tabSize > 0)
    {
        std::cout << "Podaj rozmiar tablicy: ";
        std::cin >> tabSize;
        int tab[tabSize]; //jak w tym przypadku będzie alokowana pamięć?
        for (int i = 0; i < tabSize; i++)
        {
            tab[i] = i;
        }
        for (int i = 0; i < tabSize; i++)
        {
            std::cout << tab[i] << std::endl;
        }

        std::cout << &tab[0] << std::endl;
        std::cout << &myTab[0] << std::endl;
    }
    return 0;
}
