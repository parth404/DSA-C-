// Find pivot element in an array

// the element on which monotonic pattern breaks or order breaks is known as pivot

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
        {
            return arr[mid - 1];
        }

        if (arr[s] > arr[mid])
        {
            e = mid - 1; // search lhs
        }
        else if (arr[s] < arr[mid])
        {
            s = mid + 1; // search rhs
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{7, 1, 2, 3, 4, 5, 6};

    cout << "Pivot element = " << findPivot(arr) << endl;

    return 0;
}
