// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown

// pivot index k (1 <= k < nums.length) such that the resulting array is

// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).

// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target,

// return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

// -----------------------------------------------------------------------------------------------------solution----------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int pivot)
{
    int s = start;
    int e = pivot;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (target == arr[mid])
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }

        if (arr[s] > arr[mid])
        {
            e = mid - 1; // search lhs
        }
        else if (arr[s] < arr[mid])
        {
            s = mid + 1; // search rhs
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int search(vector<int> arr, int target)
{
    int pivotIndex = findPivot(arr);

    if (target >= arr[0] && target <= arr[pivotIndex])
    {
        int ans = binarySearch(arr, target, 0, pivotIndex);
        cout << ans << endl;
        return ans;
    }

    if (pivotIndex + 1 < arr.size() && target >= arr[pivotIndex + 1] && target <= arr[arr.size() - 1])
    {
        int ans = binarySearch(arr, target, pivotIndex + 1, arr.size() - 1);
        return ans;
    }
    return -1;
}

int main()
{
    vector<int> arr{4, 5, 6, 7, 0, 1, 2};
    int target = 3;
    cout << "target is at index " << search(arr, target) << endl;
    return 0;
}
