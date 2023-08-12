// There is an integer array arr sorted in ascending order (with distinct values).

// Prior to being passed to your function, arr is possibly rotated at an unknown

// pivot index k (1 <= k < arr.length) such that the resulting array is

// [arr[k], arr[k+1], ..., arr[n-1], arr[0], arr[1], ..., arr[k-1]] (0-indexed).

// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array arr after the possible rotation and an integer target,

// return the index of target if it is in arr, or -1 if it is not in arr.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: arr = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: arr = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: arr = [1], target = 0
// Output: -1

// -----------------------------------------------------------------------------------------------------solution----------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
using namespace std;

// for rotated and sorted array, pivot divides the array into two sorted subsets

// find pivot index
int findPivot(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // CASE 1: pivot will be equal to s for single element array or if s=e
        if (s == e)
        {
            return s;
        }
        // CASE 2: pivot element can be on mid, mid+1 or mid-1
        //  pivot element will be the max number of these three
        if (mid + 1 <= e && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        if (mid - 1 >= s && nums[mid - 1] > nums[mid])
        {
            return mid - 1;
        }
        // CASE 3: Pivot can exist within the two subsets
        // check left subset
        if (nums[s] > nums[mid])
        {
            e = mid - 1; // search lhs
        }
        else // if mid > s
        {
            s = mid + 1;
        }
        // update mid
        mid = s + (e - s) / 2;
    }
    return -1;
}

// find target
int searchTarget(vector<int> &nums, int target, int s, int e)
{
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            e = mid - 1; // search lhs
        }
        else
        {
            s = mid + 1; // search rhs
        }
        // update mid
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int pivot = findPivot(nums);
    // if target not in nums
    int ans = -1;
    // as pivot divides array into two subsets
    // for left subset, start search from 0 index
    if (target >= nums[0] && target <= nums[pivot])
    {
        ans = searchTarget(nums, target, 0, pivot);
    }
    else
    {
        ans = searchTarget(nums, target, pivot + 1, nums.size() - 1);
    }

    cout << "target is at index " << ans << endl;

    return 0;
}
