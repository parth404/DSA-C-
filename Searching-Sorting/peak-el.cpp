// An array arr is a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1
// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1

#include <iostream>
#include <vector>
using namespace std;

// to use binary search, we divide the array into two subsets which are sorted,
// increasing and decreasing order
// A=[0,2] B=[2,1,0]

int findPeak(vector<int> v)
{

    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        // i<i+1 for line A and peak is on rhs of line A, hence
        if (v[mid] < v[mid + 1])
        {
            s = mid + 1; // search rhs
        }
        else // i>i+1 for line B and peak lies on rhs of line B
        {
            // also i can be peak index or peak lies on line B, hence
            e = mid; // e = mid as we could be standing on peak and we don't want to lose it in our search
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{

    vector<int> v{0, 10, 5, 2};

    cout << "Peak el is " << findPeak(v) << endl;

    return 0;
}