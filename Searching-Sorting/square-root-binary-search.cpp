// sqr root of a number n will lie between 0 to n.
// here 0 to n, is search space

#include <iostream>
#include <vector>
using namespace std;

int findRoot(int n)
{
    // create search space
    vector<int> arr;
    for (int i = 1; i <= 25; i++)
    {
        arr.push_back(i);
    }

    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        int el = arr[mid];

        if (n == el * el)
        {
            return el;
        }
        else if (el * el > n)
        {
            e = mid - 1; // search in rhs
        }
        else if (el * el < n)
        {
            ans = el;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    int n;
    cout << "enter the number" << endl;
    cin >> n;

    int ans = findRoot(n);

    int precision;
    cout << "enter precision" << endl;
    cin >> precision;

    double step = 0.1;

    double finalAns = ans + step;

    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * j < n; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "final answer is = " << finalAns << endl;

    return 0;
}