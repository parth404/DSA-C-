// 242. Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word
// or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    // INPUT
    string s;
    cin >> s;
    string t;
    cin >> t;

    // OUTPUT
    cout << isAnagram(s, t);

    return 0;
}