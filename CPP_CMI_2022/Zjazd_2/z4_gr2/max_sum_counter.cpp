#include <iostream>
#include <cstdlib> // dla C

using namespace std;

long int countMaxSum(int *nums, const int n);

int main(int argc, char *argv[])
{
    const int n = 25;
    int nums[n] = {3, -2, -1, -1, -1, -2, -4, -10, -10, -10, -8, 10,
                   3, -2, -1, -1, -1, -2, -4, -10, -10, -10, -10, -8, 10};

    long int maxSum = countMaxSum(nums, n);
    cout << "Max sum: " << maxSum << endl;

    return 0;
}

long int countMaxSum(int *nums, const int n)
{
    int result;
    int maxMove = 6;
    int prevId;
    long int prevMax;
    long int *summedNums = new long int[n]; // dla C++
    // long int* summedNums = (long int*) malloc( n * sizeof(long int) ); // dla C

    summedNums[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prevId = i - 1;
        prevMax = summedNums[prevId];

        for (int j = prevId - 1; j >= 0 && j + maxMove > prevId; j--)
        {
            if (summedNums[j] > prevMax)
            {
                prevMax = summedNums[j];
            }
        }

        summedNums[i] = nums[i] + prevMax;
    }

    result = summedNums[n - 1];

    delete[] summedNums; // dla C++
    // free(summedNums); // dla C

    return result;
}
