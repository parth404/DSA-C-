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
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    // store ans
    string ans;
    // iterator
    int i = 0;

    while (true)
    {
        char curr_ch = 0; // current character to compare with characters of other strings
        // iterate through all strings in vector strs
        for (auto str : strs)
        {
            // if out of bound
            if (i >= strs.size())
            {
                curr_ch = 0;
                break;
            }
            // At the begining
            if (curr_ch == 0)
            {
                curr_ch = str[i]; // set first character of first item as current character
            }
            else if (str[i] != curr_ch) // if item's current character doesn't match previous items respective character
            {
                curr_ch = 0;
                break;
            }
        }
        if (curr_ch == 0) // if current character is reset to 0
        {
            break;
        }
        ans.push_back(curr_ch);
        i++; // move to next character
    }
    return ans;
}

int main()
{
    vector<string> strs{"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs) << endl;
    return 0;
}