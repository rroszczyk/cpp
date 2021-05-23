#include <iostream>
#include <stdio.h>
#include <bitset> 
#include <math.h>   

using namespace std;

int wyrownajDlugosc(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();

	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++) 
		{
			str1 = '0' + str1;
		}
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++) 
		{
			str2 = '0' + str2; 
		}
	}
	return len1; 
}

string dodajBinarnie(string first, string second)
{
	string result; 

	int length = wyrownajDlugosc(first, second);
	int carry = 0; 

	for (int i = length - 1; i >= 0; i--)
	{
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';
		int sum = (firstBit ^ secondBit ^ carry) + '0';

		result = (char)sum + result;

		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}

	if (carry) 
	{
		result = '1' + result;
	}

	return result;
}

int wymnozBit(string a, string b)
{
	return (a[0] - '0') * (b[0] - '0');
}

long int mnozenie(string X, string Y)
{
	int n = wyrownajDlugosc(X, Y);

	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return wymnozBit(X, Y);
	}

	int fh = n / 2;	  
	int sh = (n - fh); 

	string Xl = X.substr(0, fh);
	string Xr = X.substr(fh, sh);
	string Yl = Y.substr(0, fh);
	string Yr = Y.substr(fh, sh);

	long int P1 = mnozenie(Xl, Yl);
	long int P2 = mnozenie(Xr, Yr);
	long int P3 = mnozenie(dodajBinarnie(Xl, Xr), dodajBinarnie(Yl, Yr));

	return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

string mnozenieStr(string X, string Y)
{
	long int result = mnozenie(X, Y);
	string s = std::bitset<64>(result).to_string();

	unsigned bits=(result<=1)+(result<0);
	while(result>>=1) ++bits;
	
	return s.substr(64 - bits - 1);
}

int main()
{
    cout << "Dodawanie 1100011 + 10 = " << dodajBinarnie("1100011", "10") << "\n";

	cout << "Mnożenie 1100 * 1010 = " << mnozenieStr("1100", "1010") << "\n";
	cout << "Mnożenie 110 * 1010 = " << mnozenieStr("110", "1010") << "\n";
	cout << "Mnożenie 11 * 1010 = " << mnozenieStr("11", "1010") << "\n";
	cout << "Mnożenie 1 * 1010 = " << mnozenieStr("1", "1010") << "\n";
	cout << "Mnożenie 0 * 1010 = " << mnozenieStr("0", "1010") << "\n";
	cout << "Mnożenie 111 * 1111 = " << mnozenieStr("111", "111") << "\n";
	cout << "Mnożenie 11 * 11 = " << mnozenieStr("11", "11") << "\n";
}
