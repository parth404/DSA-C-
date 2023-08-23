// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int i = 0;

    while (true)
    {
        char curr = 0;
        for (auto str : strs)
        {
            if (i >= str.size())
            {
                curr = 0;
                break;
            }
            if (curr == 0)
            {
                curr = str[i];
            }
            else if (str[i] != curr)
            {
                curr = 0;
                break;
            }
        }
        if (curr == 0)
        {
            break;
        }
        ans.push_back(curr);
        i++;
    }

    return ans;
}

int main()
{
    vector<string> strs{"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << endl;
    return 0;
}