#include <iostream>

using namespace std;

int main()
{
    cout << "Hello\n";
    int a = 12;
    int b = 3;
    cout << "a = " << a << endl;

    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;

    int *c;
    c = &a;
    cout << "&c = " << &c << endl;
    cout << "c = " << c << endl;
    cout << "*c = " << *c << endl;

    a = 100;
    cout << "a = " << a << endl;
    cout << "*c = " << *c << endl;

    int n = 20;
    int *nums = (int *)malloc(sizeof(int) * n);
    if (nums == NULL)
    {
        cerr << "Cannot alloc memory for nums!" << endl;
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "nums[" << i << "] = " << nums[i] << endl;
    }

    free(nums);
    return 0;
}
