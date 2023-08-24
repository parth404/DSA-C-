// 345. Reverse Vowels of a String

// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u',
// and they can appear in both lower and upper cases, more than once.

// Example 1:

// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);

    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s)
{
    int l = 0;
    int h = s.length() - 1;

    while (l < h)
    {
        if (!isVowel(s[l]))
        {
            l++;
        }
        else if (!isVowel(s[h]))
        {
            h--;
        }

        if (isVowel(s[l]) && isVowel(s[h]))
        {
            swap(s[l], s[h]);
            l++;
            h--;
        }
    }
    return s;
}

int main()
{
    // INPUT
    string s;
    cin >> s;

    // OUTPUT
    cout << reverseVowels(s) << endl;
    return 0;
}
