// 28. Find the Index of the First Occurrence in a String

// Given two strings needle and haystack, return the index of the first occurrence
// of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// -------------------------Approach 1----------------------------------------------

// int strStr(string haystack, string needle)
// {
//     int start = 0;
//     int end = haystack.size() - 1;
//     while (start <= end)
//     {
//         if (haystack.substr(start, needle.size()) == needle)
//         {
//             return start;
//         }
//         else
//         {
//             start++;
//         }
//     }
//     return -1;
// }

// -------------------------Approach 2----------------------------------------------

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (needle[j] != haystack[i + j])
            {
                break;
            }
            if (j == m - 1) // if j is at the last index it means it is a substring of haystack. eg: for needle = "sad", last index will be m-1 = 2
            {
                return i; // i will be the first index
            }
        }
    }
    return -1;
}

int main()
{
    string haystack;
    cin >> haystack;
    string needle;
    cin >> needle;

    cout << strStr(haystack, needle) << endl;
}