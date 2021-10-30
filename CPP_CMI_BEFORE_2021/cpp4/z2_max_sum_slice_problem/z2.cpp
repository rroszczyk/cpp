#include <iostream>
#include <cmath>

using namespace std;

void printResult(int nums[], int start, int end, int maxSum){
	cout << "[";
	for(int i = start; i <= end; i++){
		cout << nums[i];
		if( i < end ){
			cout << ", ";
		}
	}
	cout << "]\n";

	cout << "Suma znalezionego podciągu: " << maxSum << "\n";
}

int main(int argc, char* argv[]){
	int n = 10;
	int nums[n];

	for(int i = 0; i < n; i++){
		cout << "Podaj " << i + 1 << " liczbę\n";
		cin >> nums[i];
	}

	cout << "Wczytane liczby: ";
	for(int i = 0; i < n; i++){
		cout << nums[i] << " ";
	}
	cout << "\n";

	int maxSum = nums[0];
	int sum;
	int final_i = 0, final_j = 0;

	for(int i = 0; i < n; i++){
		sum = 0;

		for(int j = i; j < n; j++){
			sum += nums[j];
			maxSum = max(sum, maxSum);
			if( sum == maxSum ){
				final_i = i;
				final_j = j;
			}
		}
	}

	printResult(nums, final_i, final_j, maxSum);

	return 0;
}
