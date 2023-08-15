// Bubble Sort
// for every ith round, place the largest ith element to its right position

// T.C
// normal case: where we need to compare and swap positions in every round n(n-1)/2
// t.c = O(n2)

// best case: already sorted array. here we need to swap and compare only in first round. no of comparisons = n-1
// t.c = O(n-1) , which can be considered O(n)

// worst case: reverse sorted, comparisons n(n-1)/2
// t.c = O(n2)

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size();

    // iterate through elements(starting from round 1 instead of 0 to simplify logic)
    for (int round = 1; round < n; round++)
    {
        bool swapped = false;
        // for every ith round find largest element
        for (int j = 0; j < n - round; j++)
        {
            // compare element with next element to find largest
            if (arr[j] > arr[j + 1])
            {
                // swap position if current element is larger
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false)
        {
            // if already sorted, then exit loop
            break;
        }
    }

    // print sorted array
    cout << "sorted array is " << endl;
    for (auto val : arr)
    {
        cout << val << " ";
    }
}