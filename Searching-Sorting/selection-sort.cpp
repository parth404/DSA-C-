// Selection sort

// in selection sort we start from i=0, then look for the minimum number
// starting from i=0 to arr.size() -1
// then swap min number with current index, starting with i=0
// then proceed to next index, i=1, and repeat the same
// till we reach n-1, last index. last index will already be sorted

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr{5, 4, 3, 2, 1};
    int n = arr.size();

    // traverse through array elements till n-1
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        // find minimum between elements from current index:i+1 to n
        //  compare with all elements in that range
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                // update minIndex
                minIndex = j;
            }
        }
        // swap with current element
        swap(arr[i], arr[minIndex]);
    }

    // print sorted array
    cout << "sorted array is " << endl;
    for (auto val : arr)
    {
        cout << val << " ";
    }
}