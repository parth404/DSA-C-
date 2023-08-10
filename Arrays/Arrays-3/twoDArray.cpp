#include <iostream>
using namespace std;

int main()
{
    // declare & initialising 2D array
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // we can find linear index of 2d array elements using formula c*i+j
    // where c is no. of cols, i and j are current row and column

    // To print an element we specify row and column position i&j
    // cout << arr[1][1] << endl;

    // INPUT

    // we can access array row wise or column wise

    cout << "Enter Input for 2D Array" << endl;
    int brr[4][3];
    int rows = 4;
    int cols = 3;

    // row wise input
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> brr[i][j];
        }
    }

    // OUTPUT

    // we can print array row wise or column wise

    // To print row-wise
    cout << "print array row-wise" << endl;
    // outer loop rows
    for (int i = 0; i < rows; i++)
    {
        // for every loop print element of each column
        for (int j = 0; j < cols; j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    // To print col-wise
    cout << "print array col-wise" << endl;
    // outer loop cols
    for (int i = 0; i < cols; i++)
    {
        // for every loop print element of each row
        for (int j = 0; j < rows; j++)
        {
            cout << brr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}