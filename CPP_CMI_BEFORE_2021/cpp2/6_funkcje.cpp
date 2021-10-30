#include <iostream>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"      /* Black */
#define RED         "\033[31m"      /* Red */
#define GREEN       "\033[32m"      /* Green */
#define YELLOW      "\033[33m"      /* Yellow */
#define BLUE        "\033[34m"      /* Blue */
#define MAGENTA     "\033[35m"      /* Magenta */
#define CYAN        "\033[36m"      /* Cyan */
#define WHITE       "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

using namespace std;

struct argumenty {
    int a;
    int b;
};

argumenty wczytaj() 
{
    argumenty arg;

    cout << YELLOW << "podaj pierwszą liczbę: " << RESET;
    cin >> arg.a;
    cout << YELLOW << "podaj drugą liczbę: " << RESET;
    cin >> arg.b;
    return arg;
}

void pomoc()
{
    cout << GREEN << "[1] - dodawanie" << endl << RESET;
    cout << GREEN << "[2] - odejmowanie" << endl << RESET;
    cout << GREEN << "[0] - wyjscie z programu" << endl << RESET;
    cout << YELLOW << "jaką operacje chcesz wykonać? " << RESET;
}

int dodawanie(argumenty arg)
{
    int result = arg.a + arg.b;

    cout << BOLDGREEN << "wynik dodawania liczb: " << result << endl << RESET;

    return result;
}

int odejmowanie(argumenty arg)
{
    int result = arg.a - arg.b;

    cout << BOLDGREEN << "wynik odejmowania liczb: " << result << endl << RESET;

    return result;

}

int main()
{
    system ("clear");       // coby ekran zawsze był czysty :)
    cout << RED << "W programie sa dostepne nastepujace opcje:" << endl << RESET;
    
    int liczba;

    do
    {
        pomoc();
        cin >> liczba;
        switch (liczba)
        {
            case 0:
                cout << BOLDMAGENTA << "dziękuje i miłego dnia \n" << RESET;
                break;
            case 1: {
                argumenty arg = wczytaj();
                dodawanie(arg);
                break;
            }
            case 2: {
                argumenty arg = wczytaj();            
                odejmowanie(arg);
                break;
            }
            default:
                cout << BOLDMAGENTA << "takiej funkcjonalności jeszcze nie ma \n" << RESET;
                break;
        
        } //switch
    } while (liczba != 0);
   
    return 0;
}