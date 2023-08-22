// 539. Minimum Time Difference

// Given a list of 24-hour clock time points in "HH:MM" format,
// return the minimum minutes difference between any two time-points in the list.

// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

// Constraints:

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    vector<int> minutes;
    for (int i = 0; i < timePoints.size(); i++)
    {
        // convert to integer
        int hours = stoi(timePoints[i].substr(0, 2));
        int min = stoi(timePoints[i].substr(3, 2));
        // convert hours to minutes
        int total = hours * 60 + min;
        // push converted minutes to minutes array
        minutes.push_back(total);
    }

    // sort minutes array -> T.C O(logn)
    sort(minutes.begin(), minutes.end());

    // find minimum difference
    int mini = INT8_MAX;
    int n = minutes.size();

    for (int i = 0; i < n - 1; i++)
    {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }

    // calculate diff of last value with first value to handle "00:00" = 12:00 AM
    // as time is circular we add 24hours to first value
    // 24hours in minutes is 24*60 = 1440

    int lastDiff1 = (minutes[0] + 1440) - minutes[n - 1];
    int lastDiff2 = minutes[n - 1] - minutes[0];
    int lastDiff = min(lastDiff1, lastDiff2);

    return min(mini, lastDiff);
}

int main()
{
    vector<string> timePoints{"00:00", "23:59", "00:00"};

    cout << "the minimum minutes difference is = " << findMinDifference(timePoints) << endl;

    return 0;
}