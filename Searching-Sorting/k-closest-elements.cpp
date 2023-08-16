// Find K closest elements

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b

// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int k = 4;
    int x = 35;

    // Two pointer approach
    int l = 0;              // lowest position starting index
    int h = arr.size() - 1; // highest position ending index
    while (h - l >= k)
    {
        // compare difference between low and x with high and x
        if (x - arr[l] > arr[h] - x)
        {
            l++; // move low towards value of x.
        }
        else
        {
            h--; // move high towards x
        }
    }

    vector<int> ans;
    for (int i = l; i <= h; i++)
    {
        ans.push_back(arr[i]);
    }

    for (auto val : ans)
    {
        cout << val << " ";
    }

    // T.C for above solution
    // comaprisions were in the range n -> K
    // O(n-k)

    // S.C
    //

    return 0;
}