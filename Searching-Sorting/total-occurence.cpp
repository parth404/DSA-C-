// Find the total occurence of an element

#include <iostream>
#include <vector>
using namespace std;

// Find first occurence
int firstOcc(vector<int> v, int target)
{

    // created start end and mid variables seperately to find first and last occurence
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;
    int first = -1;

    while (start <= end)
    {
        // define middle element in array
        int element = v[mid];
        if (element == target)
        {
            // store answer mid (mid point)
            first = mid;
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

    return first;
}

// Find last occurence
int lastOcc(vector<int> v, int target)
{
    int s = 0;
    int e = v.size() - 1;
    int m = s + (e - s) / 2;
    int last = -1;

    while (s <= e)
    {
        int element = v[m];
        if (element == target)
        {
            // store m (mid point) as ans
            last = m;
            // search in rhs
            s = m + 1;
        }
        else if (target > element)
        {
            // search in rhs
            s = m + 1;
        }
        else if (target < element)
        {
            // search in lhs
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }

    return last;
}

int main()
{

    vector<int> v{1, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 6, 7};
    int target = 3;

    int first = firstOcc(v, target);
    int last = lastOcc(v, target);

    if (first == -1 || last == -1)
    {
        cout << "element doesn't exist" << endl;
    }
    else
    {
        // to find total occurence we can use lastOcc - firstOcc + 1
        cout << "total occurence of " << target << " is " << last - first + 1 << endl;
    }

    return 0;
}