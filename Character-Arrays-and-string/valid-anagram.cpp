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

// BRUTE FORCE -> T.C : )(nlogn)
// bool isAnagram(string s, string t)
// {
//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());

//     if (s == t)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// BETTER APPROACH -> Frequency Table for Strings

// TOTAL ASCII = 256
bool isAnagram(string s, string t)
{
    // since ACII characters lie from 0 to 256
    // we can create an array of length 256 and initialize it with 0 (all 0 elements)
    // indexes from 0 to 256 represent ASCII values
    int freqTable[256] = {0};

    // Our approach invloves looping through the string and increasing count
    // for respective ASCII values as they occur in the first string
    for (int i = 0; i < s.length(); i++)
    {
        freqTable[s[i]]++;
    }

    // Now we can decrease count of the ACII values for the second string
    for (int i = 0; i < t.length(); i++)
    {
        freqTable[s[i]]--;
    }

    // If the strings are anagram, all values in the array will be reset to 0
    for (int i = 0; i < 256; i++)
    {
        if (freqTable[i] != 0)
            return false;
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
    if (isAnagram(s, t))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}