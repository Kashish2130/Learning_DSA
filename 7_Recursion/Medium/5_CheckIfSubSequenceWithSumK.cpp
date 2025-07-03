#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr, int target, int sum, int idx)
{
    // Base Case: Reached end of array
    if (idx == arr.size())
    {
        return sum == target;
    }

    // Include current element
    if (helper(arr, target, sum + arr[idx], idx + 1))
        return true;

    // Exclude current element
    if (helper(arr, target, sum, idx + 1))
        return true;

    return false;
}

bool isAnyPerfectSum(vector<int> &arr, int target)
{
    return helper(arr, target, 0, 0);
}