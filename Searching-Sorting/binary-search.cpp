// Binary search will only work for monotonic array or sorted array

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{

    int start = 0;
    int end = size - 1;
    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            // search in lhs
            end = mid - 1;
        }
        else
        {
            // search in rhs
            start = mid + 1;
        }

        mid = (start + end) / 2;

        // element not found
    }
    return -1;
}

int main()
{

    int arr[] = {2, 4, 6, 8, 10, 12, 16};
    int size = 7;
    int target = 10;

    // using binary search to find target in array and
    // returning index or returning -1 if target not found

    int indexOfTarget = binarySearch(arr, size, target);

    if (indexOfTarget == -1)
    {
        cout << "Target not found" << endl;
    }
    else
    {
        cout << "Target found at " << indexOfTarget << " index" << endl;
    }

    return 0;
}