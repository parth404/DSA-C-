// Find the last occurence of an difference

#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> v)
{

    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s < e)
    {
        int el = v[mid];
        if (el > v[mid + 1])
        {
            // search lhs
            e = mid;
        }
        else if (el < v[mid + 1])
        {
            ans = v[mid + 1];
            // search rhs
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    vector<int> v{1, 6, 8, 14, 12};

    cout << "Peak el is " << findPeak(v) << endl;

    return 0;
}