// Binary search in 2d array

// for 2d array
// linear index of array is given by => c*i+j, where cis no. of cols, i & j are row and col number of the element
// Index of row and col of a 2d array
// from linear index is given by =>
// rowIndex = mid/cols
// colIndex = mid%cols

#include <iostream>
#include <vector>
using namespace std;

bool twoDSearch(int arr[][4], int rows, int cols, int target)
{
    int s = 0;
    int e = (rows * cols) - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int rowIndex = mid / cols;
        int colIndex = mid % cols;
        int el = arr[rowIndex][colIndex];

        if (el == target)
        {
            cout << "Target found at " << rowIndex << " " << colIndex << endl;
            return true;
        }
        else if (el < target)
        {
            s = mid + 1; // search rhs
        }
        else
        {
            e = mid - 1; // search lhs
        }
        mid = s + (e - s) / 2;
    }
    return false;
}

int main()
{
    int arr[5][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int rows = 5;
    int cols = 4;
    int target;
    cout << "enter target" << endl;
    cin >> target;
    int ans = twoDSearch(arr, rows, cols, target);
    if (ans)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}