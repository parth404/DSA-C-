// You are given an array consisting of n integers which denote the position of a stall.
// You are also given an integer k which denotes the number of aggressive cows.
// You are given the task of assigning stalls to k cows such that the minimum distance
// between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.

// Example 1:

// Input:
// n=5
// k=3
// stalls = [1 2 4 8 9]
// Output:
// 3
// Explanation:
// The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[2] and
// the third cow can be placed at stalls[3].
// The minimum distance between cows, in this case, is 3,
// which also is the largest among all possible ways.

// Example 2:

// Input:
// n=5
// k=3
// stalls = [10 1 2 7 5]
// Output:
// 4
// Explanation:
// The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[1] and
// the third cow can be placed at stalls[4].
// The minimum distance between cows, in this case, is 4,
// which also is the largest among all possible ways.
// Your Task:
// Complete the function int solve(), which takes integer n, k, and a vector stalls with
// n integers as input and returns the largest possible minimum distance between cows.

// Expected Time Complexity: O(n*log(10^9)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 2 <= n <= 10^5
// 2 <= k <= n
// 0 <= stalls[i] <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int sol)
{
    int pos = stalls[0];
    int count = 1;

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= sol)
        {
            count++;
            pos = stalls[i];
        }
        if (count == k)
        {
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls{1, 2, 4, 8, 9};
    int n = 5;
    int k = 3;

    // The largest possible minimum distance between cows
    int result = solve(n, k, stalls);

    cout << "ans is = " << result << endl;
    return 0;
}