#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n = 24;
    int nums[n] = {3, -2, -1, -1, -1, -2, -4,
                   -10, -10, -10, -8, 10, 3, -2, -1,
                   -1, -1, -2, -4, -10, -10, -10, -8, 10};
    int max_step = 6;
    int max_val;

    for (int i = 1; i < n; i++)
    {
        max_val = nums[i - 1];
        for (int j = i - 2; j >= 0 && j + max_step >= i; j--)
        {
            if (nums[j] > max_val)
            {
                max_val = nums[j];
            }
        }
        nums[i] = max_val + nums[i];
    }
    int result = nums[n - 1];
    cout << "Result = " << result << endl;

    return 0;
}
