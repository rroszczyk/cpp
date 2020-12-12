#include <iostream>
#include <cmath>

using namespace std;

double scalarProduct(int n, double x[], double y[]);

double vectorLen(int n, double x[]);

void unitNorm(int n, double x[]);

int main(int argc, char *argv[]) {
    cout << "Podaj liczbę elementów wektora\n";
    cout << "a następnie podaj te elementy.\n";

    int n;
    cin >> n;
    double x[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Długość wektora: " << vectorLen(n, x) << endl;
    unitNorm(n, x);
    cout << "Długość wektora (po normalizacji): " << vectorLen(n, x) << endl;

    return 0;
}

double scalarProduct(int n, double x[], double y[]) {
    double result = 0;

    for (int i = 0; i < n; i++) {
        result += x[i] * y[i];
    }
    return result;
}

double vectorLen(int n, double x[]) {
    double scalarProd = scalarProduct(n, x, x);
    double result = sqrt(scalarProd);
    return result;
}

void unitNorm(int n, double x[]) {
    double vecLen = vectorLen(n, x);

    for (int i = 0; i < n; i++) {
        x[i] /= vecLen;
    }
}
