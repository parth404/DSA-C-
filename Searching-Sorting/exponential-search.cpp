// Exponential Search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs(int arr[], int s, int e, int x)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (x > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int x = 3;
    int n = sizeof(arr) / sizeof(int);
    int result;
    // using exponential search we try to find a subset within the array which will be our search space
    if (arr[0] == x)
    {
        result = 0;
    }
    int i = 1;
    while (i < n && arr[i] <= x)
    {
        // in exponential search we double the index (i = i*2)
        i = i * 2;
    }
    result = bs(arr, i / 2, min(i, n - 1), x);

    cout << "index of x = " << result << endl;

    return 0;
}

// T.C of exponential array
