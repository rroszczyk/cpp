#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	int daysInYear = 365;
	int daysInWeek = 7;

	int result_1 = daysInYear / daysInWeek;

	cout << "Result 1: " << result_1 << "\n";

	float nearTwo = 1.999;
	int floor = nearTwo;
	cout << "floor: " << floor << "\n";

	bool raining = 1;
	bool sunny = true;
	bool warm = false;

	cout << "Is raining? " << raining << "\n";
	cout << "Is sunny? " << sunny << "\n";
	cout << "Is warm outside? " << warm << "\n";

	char letter_a = 'a';
	char letter_B = 'B';

	cout << "Letter a: " << (int) letter_a << "\n";
	cout << "Letter B: " << (int) letter_B << "\n";

	string declaration = "Kocham CMI (bo jest sobota).";
	cout << "Sentence: \"" << declaration << "\"\n";

	return 0;
}
