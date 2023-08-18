// You have N books, each with Ai number of pages. M students need to be allocated contiguous books,
// with each student getting at least one book. Out of all the permutations, the goal is to find
// the permutation where the student with the most books allocated to him gets the minimum number
// of pages, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findPages() which
// takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.

// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= A [ i ] <= 106
// 1 <= M <= 105

#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSoln(int A[], int N, int M, int sol)
{
    int pageSum = 0; // sum of pages for books allocated
    int count = 1;   // count represents each iteration for allocation to each student

    // Iterate through each book to see if correct allocation is possible
    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol) // if number of pages in one book itself is greater than solution
        {
            return false;
        }
        if (pageSum + A[i] > sol) // check if adding next book increases pages more than that in solution
        {
            count++;
            pageSum = A[i];
            if (count > M) // count exceeds more than number of students if books are still unallocated
            {
                return false;
            }
        }
        else
        {
            pageSum += A[i]; // add pages of current book to pageSum
        }
    }
}

int findPages(int A[], int N, int M)
{
    // if no of students > no of books
    if (M > N)
    {
        return -1;
    }
    // define a search space from 0 to total number of pages and use binary search to find correct solution
    int start = 0;
    int end = accumulate(A, A + N, 0); // total number of pages in array
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSoln(A, N, M, mid))
        {
            ans = mid;     // store possible solution
            end = mid - 1; // search lhs as next solution has to be smaller than current solution
        }
        else
        {
            start = mid + 1; // search rhs as solution has to be greater than current incorrect solution
        }
    }
    return ans;
}

int main()
{
    int A[] = {12, 34, 67, 90};
    // Number of Books
    int N = 4;
    // Number of Students
    int M = 2;

    // minimum number of pages out of all possible permutations
    int result = findPages(A, N, M);

    cout << "Ans is = " << result << endl;

    return 0;
}