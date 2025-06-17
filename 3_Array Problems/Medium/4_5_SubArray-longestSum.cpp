//?Given an integer array nums, find the subarray with the largest sum, and return its sum.

//! THIS CODE IS FOR FINDING THE SUBARRAY WITH THE MAXIMUM SUM
//* The code uses brute force and optimal approaches to find the maximum sum subarray.
//* The brute force approach generates all possible subarrays and calculates their sums.
//* The optimal approach uses Kadane's algorithm to find the maximum sum subarray in linear time.

//* The brute force approach is inefficient and has a time complexity of O(n^3) and space complexity of O(n^3).
//* The optimal approach has a time complexity of O(n) and space complexity of O(1).

//* The brute force approach is not recommended for large input sizes due to its inefficiency.
//* The optimal approach is recommended for finding the maximum sum subarray efficiently.

//* The code also includes a brute force approach using maps to store subarrays and their sums.
//* The brute force approach using maps has a time complexity of O(n^3 log n) and space complexity of O(n^3).

// brute force - very inefficient
// using maps
// tc : o(n^3) [below is the reasoning]
// So, for each insertion in the map:
// Time = O(n) (comparison) × O(log m) (binary search in map) = O(n log n^2) = O(n log n) (approx)
// And you do this for all O(n^2) subarrays ⇒ Total time = O(n^3 log n)
// sc : o(n^3) [for storing all subarrays in the map each of size upto n]

#include <iostream>
#include <vector>
#include <map>
using namespace std;

pair<vector<int>, int> maxSubArrayWithMap(vector<int> &nums)
{
    map<vector<int>, int> subarraySums;
    int n = nums.size();

    // Generate all subarrays
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            temp.push_back(nums[j]);
            sum += nums[j];
            subarraySums[temp] = sum;
        }
    }

    // Find the subarray with the maximum sum
    vector<int> maxSubarray;
    int maxSum = INT_MIN;

    for (auto &it : subarraySums)
    {
        if (it.second > maxSum)
        {
            maxSum = it.second;
            maxSubarray = it.first;
        }
    }

    return {maxSubarray, maxSum};
}

// brute force
// tc : o(n^2)
// sc : o(1)

class Solution
{
public:
    vector<int> maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        int start = 0, end = 0;

        for (int i = 0; i < n; i++)
        {
            int currentSum = 0;
            for (int j = i; j < n; j++)
            {
                currentSum += nums[j];
                if (currentSum > maxSum)
                {
                    maxSum = currentSum;
                    start = i;
                    end = j;
                }
            }
        }

        // Create the result subarray from start to end
        vector<int> result;
        for (int k = start; k <= end; k++)
        {
            result.push_back(nums[k]);
        }

        return {maxSum, result};
    }
};

// optimal approach
// tc : 0(n)
// sc: o(1)
// uses kadane's algorithm

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;
        int ansStart = -1;
        int ansEnd = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (sum == 0)
            {
                ansStart = i;
            }

            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
                ansEnd = i;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};

//iterate from ansStart to ansEnd and store the elements in a vector
// return the vector
// or return the sum and the vector