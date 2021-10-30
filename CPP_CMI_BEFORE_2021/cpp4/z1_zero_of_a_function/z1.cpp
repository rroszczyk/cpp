#include <iostream>

using namespace std;

double f(double x){
	return 4 *x*x - 12*x - 9;
}

int main(int argc, char* argv[]){
	for(int i = 0; i < argc; i++){
		cout << argv[i] << endl;
	}
	double a = -3;
	double b = 2;
	double p;
	double e = 0.0001;
	int maxIter = 100;
	int iter = 0;

	do{
		p = (a + b) / 2;
		if(f(a) * f(p) <= 0){
			b = p;
		}else{
			a = p;
		}
		iter++;
	}while( iter < maxIter && (b-a) > e );

	cout << "Miejsce zerowe funkcji f jest równe: " << p << "\n";

	return 0;
}
