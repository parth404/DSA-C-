// PRATA - Roti Prata

// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting.
// The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for
// the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank
// R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes
// and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata
// in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes
// he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata).
// The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

// Input
// The first line tells the number of test cases. Each test case consist of 2 lines.
// In the first line of the test case we have P the number of prata ordered.
// In the next line the first integer denotes the number of cooks L and L integers
// follow in the same line each denoting the rank of a cook.

// Output
// Print an integer which tells the number of minutes needed to get the order done.

// Example
// Input:
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

// Output:
// 12
// 36
// 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canCook(vector<int> ranks, int p, int mid)
{
    int currP = 0; // initial cooked prata count
    for (int i = 0; i < ranks.size(); i++)
    {
        int R = ranks[i], j = 1;
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + j * R <= mid)
            { // if timetaken is less tha mid keep adding
                ++currP;
                timeTaken += j * R;
                ++j;
            }
            else
            { // exit loop when timetaken is more than mid
                break;
            }
        }
        if (currP >= p)
        {
            return true;
        }
    }
    return false;
}

int sol(int p, vector<int> ranks)
{
    int s = 0;
    int highestRank = *max_element(ranks.begin(), ranks.end());
    int e = highestRank * (p * (p + 1) / 2); // using formule n(n+1)/2 to calculate sum for 1+2+3+..+n
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (canCook(ranks, p, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t; // take inputs for test cases, pratas and number of cooks

    while (t--)
    {
        // INPUT
        int p, l;
        // inputs for pratas and numbr of cooks
        cin >> p >> l;
        vector<int> ranks; // array to store ranks
        while (l--)        // take input for ranks of cooks
        {
            int r;
            cin >> r; // rank of cook
            ranks.push_back(r);
        }

        // SOLUTION
        cout << "output is = " << sol(p, ranks) << endl;
    }

    return 0;
}