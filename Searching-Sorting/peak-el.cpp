// Find Peak Element – A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input:
// nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

// Example 2:

// Input:
// nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

#include <iostream>
#include <vector>
using namespace std;

// in the array containing peak, we can observe that the array can be divided into two lines with peak in the middle,
// line A will have elements in ascending order and line B with descending order. hence BS can be used to find peak

int findPeak(vector<int> v)
{

    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        // first we need to determine which line are we on
        // is it ascending or descending
        // if ascending
        if (v[mid] < v[mid + 1])
        {
            // this can be peak or it has to be in rhs for ascending order
            s = mid + 1;
        }
        else // if descending
        {
            // we need to keep searching in lhs for descending order
            e = mid; // e = mid as we could be standing on peak and we don't want to lose it in our search
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{

    vector<int> v{2, 1};

    cout << "Peak el is " << findPeak(v) << endl;

    return 0;
}