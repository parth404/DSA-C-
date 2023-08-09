// Find the last occurence of an element

#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int> v, int target)
{

    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        // define middle element in array
        int element = v[mid];
        if (element == target)
        {
            // store answer, if this is last occurence it will be returned after the loop
            ans = mid;
            // search in rhs as last occurence has to be greater than or equal to mid
            start = mid + 1;
        }
        else if (target > element)
        {
            // search in rhs
            start = mid + 1;
        }
        else if (target < element)
        {
            // search in lhs
            end = mid - 1;
        }

        // Update value of mid, since we are changing start and end values above
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{

    vector<int> v{1, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9};
    int target = 7;

    // using binary search to find target in array and
    // returning index or returning -1 if target not found

    int indexOfLastOccurence = lastOccurence(v, target);

    if (indexOfLastOccurence == -1)
    {
        cout << "Target not found" << endl;
    }
    else
    {
        cout << "Last occurence found at " << indexOfLastOccurence << " index" << endl;
    }

    return 0;
}