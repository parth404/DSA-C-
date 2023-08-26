// 5. Longest Palindromic Substring

// Given a string s, return the longest
// palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++, end--;
    }
    return true;
}

// ----------------------------------Approach 1-----------------------------------------------------------

string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j - 1 + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int main()
{
    // INPUT
    string s;
    cin >> s;
    // OUTPUT
    cout << longestPalindrome(s) << endl;
    return 0;
}