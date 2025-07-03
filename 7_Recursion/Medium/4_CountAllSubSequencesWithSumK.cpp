#include <bits/stdc++.h>
using namespace std;

int count = 0;
void helper(vector<int> &arr, int target, int sum, int idx)
{
    // Base Case: Reached end of array
    if (idx == arr.size())
    {
        if (sum == target)
            count++;
        return;
    }

    // Include current element
    helper(arr, target, sum + arr[idx], idx + 1);

    // Exclude current element
    helper(arr, target, sum, idx + 1);
}

int perfectSum(vector<int> &arr, int target)
{
    count = 0; // Reset count
    helper(arr, target, 0, 0);
    return count;
}