#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string t;
    cin >> t;

    int hash[256] = {0};
    bool isMarked[256] = {0};

    for (int j = 0; j < s.size(); j++)
    {
        hash[s[j]] = t[j]++;
        isMarked[t[j]] = true;
    }

    for (int j = 97; j < 124; j++)
    {
        cout << hash[j] << " ";
    }

    cout << " " << endl;

    for (int j = 97; j < 124; j++)
    {
        cout << isMarked[j] << " ";
    }

    return 0;
}