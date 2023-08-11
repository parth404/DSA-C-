// Divide two numbers using binary search

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int a, int b)
{
    int s = 0;
    int e = abs(a);
    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        // ex: 6/2=3 => 6=2*3, where 6 is dividend, 2 is divisor and 3 is quotient(taking abs value to divide initially as +ve integers)
        if (abs(mid * b) == abs(a))
        {
            ans = mid;
            break;
        }
        else if (abs(mid * b) < abs(a))
        {
            ans = mid;
            s = mid + 1; // search rhs
        }
        else
        {
            e = mid - 1; // search lhs
        }
        mid = s + (e - s) / 2;
    }
    // if dividend and divosr are both -ve or both are +ve
    if ((a < 0 && b < 0) || (a > 0 && b > 0))
    {
        return ans;
    }
    else // if one of them is -ve
    {
        return -ans;
    }
}

int main()
{
    int a;
    cout << "enter dividend " << endl;
    cin >> a;

    int b;
    cout << "enter divisor " << endl;
    cin >> b;

    int ans = binarySearch(a, b);

    cout << "quotient is = " << ans << endl;

    return 0;
}