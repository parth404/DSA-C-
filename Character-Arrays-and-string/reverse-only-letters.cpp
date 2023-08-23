// 917. Reverse Only Letters

// Given a string s, reverse the string according to the following rules:

// All the characters that are not English letters remain in the same position.
// All the English letters (lowercase or uppercase) should be reversed.
// Return s after reversing it.

// Example 1:

// Input: s = "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: s = "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"

// Constraints:

// 1 <= s.length <= 100
// s consists of characters with ASCII values in the range [33, 122].
// s does not contain '\"' or '\\'.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseOnlyLetters(string s)
{
    int low = 0;
    int high = s.size() - 1;

    while (low < high)
    {
        if (isalpha(s[low]) && isalpha(s[high]))
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
        else if (!isalpha(s[low]))
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return s;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseOnlyLetters(s) << endl;
    return 0;
}