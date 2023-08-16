// Insertion sort
// we start from i+1 index, then compare with 0 to i+1 elements
// then we shift elements bigger than current element to i+1
// then we copy the value of current element to correct index

// t.c
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size();

    // iterate through elements(starting from round 1)
    for (int round = 1; round < n; round++)
    {
        // fetch
        int val = arr[round];
        int j = round - 1;
        // compare
        for (j; j >= 0; j--)
        {
            if (arr[j] > val)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // exit loop
                break;
            }
        }
        // copy
        arr[j + 1] = val; // as loop will exit after checking condition and perform an extra j-1
    }

    // print sorted array
    cout << "sorted array is " << endl;
    for (auto val : arr)
    {
        cout << val << " ";
    }
}