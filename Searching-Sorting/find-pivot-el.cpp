// Find pivot element in an array

// input: rotated & sorted array, no duplicates

// the element on which monotonic pattern breaks or order breaks is known as pivot

// EXAMPLE
// INPUT: [9,10,2,4,6,8]
// OUTPUT: 10

// SOLUTION
//  In a sorted and rotated array, the highest number has to be the pivot
//  why? bcoz when its sorted max number will be at the end, when rotated, max number will lie somewhere within the array. which will break the order
//  The pivot also divides the array into two sorted subsets A=[9,10] & B=[2,4,6,8]

// IMPORTANT : ( identifying the pivot helps us to break the array into subsets.
// this can be used to implement binary search in any array that is rotated and sorted )

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

        // FIRST CASE:

        // max number can lie on mid or on any index near mid. i.e mid+1 or mid-1

        // to find if current index is max number we can check the following conditions

        if (s == e)
        {
            // for single element in array or search space
            return arr[s];
        }
        if (mid + 1 <= e && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        if (mid - 1 >= s && arr[mid - 1] > arr[mid])
        {
            return arr[mid - 1];
        }

        // SECOND CASE:

        // The pivot can lie on subset A or B
        if (s > arr[mid])
        {
            // search lhs
            e = mid - 1;
        }
        else
        {
            // search rhs
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{2, 4, 6, 8, 9, 10};

    cout << "Pivot element = " << findPivot(arr) << endl;

    return 0;
}
