// Given a sorted array arr[] of size N, some elements of array are moved to either of the
// adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1]
// i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1].
// The task is to search for an element in this array.

// Examples :

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2
// Explanation: Output is index of 40 in given array i.e. 2

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
// Output: -1
// Explanation: -1 is returned to indicate the element is not present

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (mid - 1 >= 0 && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        if (mid + 1 < arr.size() && arr[mid + 1] == target)
        {
            return mid + 1;
        }

        if (target > arr[mid])
        {
            s = mid + 2; // adding +2 as mid+1 has already been checked above
        }
        else
        {
            e = mid - 2; // removing 2 as mid-1 has already been checked above
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 50;

    int ans = binarySearch(arr, target);

    if (ans == -1)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "index of " << target << " is " << ans << endl;
    }

    return 0;
}