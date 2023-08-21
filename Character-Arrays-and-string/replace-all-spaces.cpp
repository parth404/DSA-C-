// replace all spaces with '@'

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void replaceSpaces(char name[]) // t.c: O(n) - linear, s.c: O(1)
{
    int i = 0;
    int n = strlen(name);
    while (i < n)
    {
        if (name[i] == ' ')
        {
            name[i] = '@';
        }
        i++;
    }
}

int main()
{
    // input
    char name[100];
    cin.getline(name, 100);

    cout << "entered string is = " << name << endl;

    // reverse the string
    replaceSpaces(name);
    // print result
    cout << "replaced string is = " << name << endl;

    return 0;
}