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

	string declaration = "Kocham CMI (również w sobotę)";
	cout << "Sentence: \"" << declaration << "\"\n";

	const int myAge = 29;
	//myAge = 30; // tak nie można robić
	cout << "My age: " << myAge << "\n";

	int points[] = {20, 99, 30};
	int n = sizeof(points) / sizeof(points[0]);

	cout << "N of points: " << n << "\n";
	cout << "First point: " << points[0] << "\n";
	cout << "Last point: " << points[n-1] << "\n";
	cout << "sizeof(points): " << sizeof(points) << "\n";

	cout << "Points[1] = " << points[1] << "\n";
	points[1] = 12;
	cout << "Points[1] = " << points[1] << "\n";

	return 0;
}




















