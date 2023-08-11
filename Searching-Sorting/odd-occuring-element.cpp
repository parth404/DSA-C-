// Given an array of positive integers.
// All numbers occur an even number of times except one
// number which occurs an odd number of times.
// All repeating occurence of element appear in pairs
// & pairs are not adjacaent
// there cannot be more than 2 consequtive occurence of any element
// Find the element that Occurs Odd Number of Times in O(n) time & constant space.

// Examples :

// Input : arr = {1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4}
// Output : 3

#include <iostream>
#include <vector>
using namespace std;

int findOddOccurence(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        { // if ans is in 0th index or if s and e are same
            return s;
        }
        // as pairs will always start with even and end on odd,
        // since pair starts from even our ans is also on even index
        if (mid % 2 == 0)
        {
            // check if it's a pair
            // compare with next element which is mid+1, as pairs are in order of mid, mid+1
            //  ans cannot be a pair
            if (arr[mid] == arr[mid + 1])
            {
                // check in rhs, to compare the next pair
                s = mid + 2;
            }
            else
            {
                // check in lhs
                // since ans will also be an even number, we keep it within our search hence
                e = mid;
            }
        }
        else // if mid is a odd number,, it may be our ans
        {
            // compare to check if it's a pair
            if (arr[mid] == arr[mid - 1])
            {
                // search in rhs, if current el is a pair
                //+1 will take you to next even number, which may be ans
                s = mid + 1;
            }
            else
            {
                e = mid - 1; // -1 will take you to next even nmber, which may be ans
            }
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 4, 2, 2, 3, 3, 4, 4, 3, 3, 600, 600, 4, 4};

    int ans = findOddOccurence(arr);

    cout << "number with odd occurences is = " << arr[ans] << endl;

    return 0;
}