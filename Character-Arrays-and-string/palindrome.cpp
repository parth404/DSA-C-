// replace all spaces with '@'

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isPalindrome(char name[]) // t.c: O(n) - linear, s.c: O(1)
{
    int i = 0;
    int n = strlen(name);
    int j = n - 1;
    bool ans = true;
    while (i <= j)
    {
        if (name[j] != name[i])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return ans;
}

int main()
{
    // input
    char name[100];
    cin.getline(name, 100);

    cout << "entered string is = " << name << endl;

    // check pallindrome
    if (isPalindrome(name))
    {
        cout << name << " is a palindrome" << endl;
    }
    else
    {
        cout << name << " is not a palindrome" << endl;
    }

    return 0;
}