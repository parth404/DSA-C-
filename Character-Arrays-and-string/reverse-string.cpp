#include <iostream>
#include <string>
using namespace std;

// calculate length of string - t.c: O(n), s.c: O(1)
int getLength(char name[])
{
    int length = 0;
    int i = 0;

    while (name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

void reverseStr(char name[]) // t.c: O(n/2) => O(n) - linear, s.c: O(1)
{
    int i = 0;
    int n = getLength(name);
    int j = n - 1;

    while (i <= j)
    {
        swap(name[i], name[j]); // swap starting and ending indexes respectively
        i++;
        j--;
    }
}

int main()
{
    // input
    char name[100];
    cin >> name;

    cout << "entered string is = " << name << endl;

    // reverse the string
    reverseStr(name);
    // print result
    cout << "reversed string is = " << name << endl;

    return 0;
}