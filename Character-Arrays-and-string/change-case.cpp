// change lowercase char to uppercase

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void changeCase(char name[]) // t.c: O(n) - linear, s.c: O(1)
{
    int i = 0;
    int n = strlen(name);
    while (i < n)
    {
        if (name[i] != ' ' && name[i] >= 'a' && name[i] <= 'z')
        {
            name[i] = name[i] - 'a' + 'A'; // for upper to lower case use A - a instead
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

    // change case
    changeCase(name);
    // print result
    cout << "transformed string is:" << endl;
    cout << name << endl;

    return 0;
}