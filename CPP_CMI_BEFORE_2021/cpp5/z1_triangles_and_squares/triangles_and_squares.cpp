#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int findSquareLength(int length, int width, int height);

int nwd(int a, int b);

int findMaxSize(int length, int width, int height, int squareLength);

vector<int> findPrimeNumbers(int number);

void displayResults(int squareLength, vector<int> primes);

int main(int argc, char *argv[]) {
    int n, i, length, width, height;
    int squareLength, maxSize;
    vector<int> primes;
    string filename = "trojkaty_kwadraty.txt";

    ifstream inputFile(filename);

    if (!(inputFile >> n)) {
        cout << "Cannot read \"n\" from file.\n";
        return -1;
    }

    i = 0;
    while (i < n && inputFile >> length >> width >> height) {
        squareLength = findSquareLength(length, width, height);
        maxSize = findMaxSize(length, width, height, squareLength);
        primes = findPrimeNumbers(maxSize);
        displayResults(squareLength, primes);
        i++;
    }

    return 0;
}

int findSquareLength(int length, int width, int height) {
    return nwd(nwd(length, width), height);
}

int nwd(int a, int b) {
    int rest = a % b;

    while (rest != 0) {
        a = b;
        b = rest;
        rest = a % b;
    }
    return b;
}

int findMaxSize(int length, int width, int height, int squareLength) {
    return max(max(max(length, width), height), squareLength);
}

vector<int> findPrimeNumbers(int number) {
    int sqrtNum = sqrt(number);

    int divisor = 2;

    vector<int> primes;

    while (number > 1 && divisor <= sqrtNum) {

        while (number % divisor == 0) {
            primes.push_back(divisor);
            number /= divisor;
        }
        divisor++;
    }

    if (number > 1) {
        primes.push_back(number);
    }

    return primes;
}

void displayResults(int squareLength, vector<int> primes) {
    int n = primes.size();

    cout << squareLength << " " << n << " ";

    for (int i = 0; i < n; i++) {
        cout << primes[i] << " ";
    }
    cout << "\n";
}