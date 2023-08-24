// 205. Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same character,
// but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true

// Example 2:

// Input: s = "foo", t = "bar"
// Output: false

// Example 3:

// Input: s = "paper", t = "title"
// Output: true

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t)
{
    // if length is not same
    if (s.size() != t.size())
    {
        return false;
    }

    int freqTable[256] = {0};       // mapping of each char of string s to t
    bool isTCharsMapped[256] = {0}; // stores if t[i] char is already mapped with s[i]

    // check occurences of s

    for (int i = 0; i < s.size(); i++)
    {
        if (freqTable[s[i]] == 0 && isTCharsMapped[t[i]] == 0)
        {
            freqTable[s[i]] = t[i];
            isTCharsMapped[t[i]] = true;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (char(freqTable[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // INPUT
    string s;
    cin >> s;
    string t;
    cin >> t;

    // OUTPUT
    if (isIsomorphic(s, t))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}