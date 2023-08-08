// Find the first occurence of an element

#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> v, int target)
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
            // store answer
            ans = mid;
            // search in lhs
            end = mid - 1;
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

        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{

    vector<int> v{1, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 6, 7};
    int target = 4;

    // using binary search to find target in array and
    // returning index or returning -1 if target not found

    int indexOfFirstOccurence = firstOccurence(v, target);

    if (indexOfFirstOccurence == -1)
    {
        cout << "Target not found" << endl;
    }
    else
    {
        cout << "first occurence found at " << indexOfFirstOccurence << " index" << endl;
    }

    return 0;
}