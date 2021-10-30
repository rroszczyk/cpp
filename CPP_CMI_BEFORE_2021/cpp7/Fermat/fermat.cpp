#include <stdio.h>
#include <stdlib.h>
 
// obliczanie a^b mod m
int power_modulo_fast(int a, int b, int m)
{
    int i;
    int result = 1;
    long int x = a % m;
 
    for (i = 1; i<=b; i <<= 1)
    {
        x %= m;
        if ((b&i) != 0)
        {
            result *= x;
            result %= m;
        }
        x *= x;
    }
 
    return result % m;
}
 
// Fermat test
// retrun: 1 - prawdopodobnie liczba pierwsza
//         0 - liczba złożona
int Fermat(int n, int k)
{
    int a, i;
    srand(34234);
 
    if (n<4)
    {
        return 1;
    }
 
    for (i=0; i<k; i++)
    {
        a = 2 + (int)((n - 2) * rand() / (RAND_MAX + 1.0));
        if (power_modulo_fast(a, n - 1, n) != 1)
        {
            return 0;
        }
    }

    return 1;
}
 
int main()
{
    int n, k;
 
    printf("Podaj liczbe do sprawdzenia p: ");
    scanf("%d", &n);
 
    printf("Podaj dokladnosc sprawdzenia k: ");
    scanf("%d", &k);
 
    if (Fermat(n, k) == 1)
    {
        printf("Liczba jest prawdopodobnie pierwsza.\n");
    }
    else
    {
        printf("Liczba jest zlozona.\n");
    }
 
    return 0;
}
