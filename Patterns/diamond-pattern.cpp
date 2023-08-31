// Print Full Pyramid

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int n = num / 2;

    for (int row = 0; row < n; row++)
    {
        // spaces
        for (int col = 0; col < n - row - 1; col = col + 1)
        {
            cout << " ";
        }
        // stars
        for (int col = 0; col < row + 1; col = col + 1)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int row = 0; row < n; row++)
    {
        // spaces
        for (int col = 0; col < row; col = col + 1)
        {
            cout << " ";
        }
        // stars
        for (int col = 0; col < n - row; col = col + 1)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}