// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

// Example 1:
// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.

// Example 2:
// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

// Example 3:
// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// Binary search
int bs(vector<int> nums, int s, int x)
{
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == x)
        {
            return nums[mid];
        }
        else if (x > nums[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    int k = 1;

    // step 1: Sort the array
    sort(nums.begin(), nums.end());

    // create set to store ans, to remove duplicates
    set<pair<int, int>> ans;

    // ---------------------------------------------------------------Two Pointer Approach-----------------------------------------------------------------------------------------------------------------------------

    // Step 2: Iterate through the array and compare differences with K
    // int i = 0, j = 1;
    // while (j < nums.size())
    // {
    //     // calculate difference
    //     int diff = nums[j] - nums[i];
    //     if (diff == k)
    //     {
    //         // insert pair in ans
    //         ans.insert({nums[i], nums[j]});
    //         // increase i & j index
    //         ++i, ++j;
    //     }
    //     else if (diff > k)
    //     {
    //         i++;
    //     }
    //     else
    //     {
    //         j++;
    //     }
    //     if (i == j)
    //     {
    //         j++;
    //     }
    // }

    // ---------------------------------------------------------------Binary Search Approach-----------------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < nums.size(); i++)
    {

        // since nums[j]-nums[i]=k can be written as:
        // nums[j]=nums[i]+k
        // standing on nums[i] need to find nums[i]+k which is > nums[i]
        // thus, it will be on rhs of the sorted array
        // using Binary Search to find target nums[i]+k and return -1 if it doesn't exist:

        if ((bs(nums, i + 1, nums[i] + k)) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    cout << "Output = " << ans.size() << endl;

    return 0;
}