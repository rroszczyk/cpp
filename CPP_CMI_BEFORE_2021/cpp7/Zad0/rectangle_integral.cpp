#include <cstdio>

double fun_x(double x);

double fun_2x(double x);

double countIntegral(double (*fun)(double), int x_a, int x_b, double h);

int main(int argc, char *argv[]) {
    double (*fun1)(double) = &fun_x;
    double (*fun2)(double) = &fun_2x;
    double resultFun1 = countIntegral(fun1, 0, 1, 0.1);
    double resultFun2 = countIntegral(fun2, 0, 1, 0.1);
    printf("result fun 1 = %g\n", resultFun1);
    printf("resutl fun 2 = %g\n", resultFun2);

    return 0;
}

double countIntegral(double (*fun)(double), int x_a, int x_b, double h) {
    int n = (x_b - x_a) / h;
    double result = 0;
    double x_i;

    for (int i = 1; i <= n; i++) {
        x_i = x_a + i * h - h / 2;
        result += (*fun)(x_i);
    }
    result *= h;

    return result;
}

double fun_x(double x) {
    return x;
}

double fun_2x(double x) {
    return 2 * x;
}

