//? Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

//Recursive Approach

class Solution {
public:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add current subset to the result
        result.push_back(current);

        // Iterate over remaining elements
        for (int i = index; i < nums.size(); i++) {
            // Include nums[i]
            current.push_back(nums[i]);

            // Recursive call for next index
            generateSubsets(i + 1, nums, current, result);

            // Backtrack (remove last element)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(0, nums, current, result);
        return result;
    }
};


// Iterative approach
//It used bit manipulation!

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < pow(2, n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<int> currSTR;
                if (i & (1 << j))
                {
                    currSTR.push_back(nums[i]);
                }
            }
            result.push_back(currSTR);
        }
    }
    return result;
};

//! Certainly! Here’s an easy explanation of the bit manipulation logic for generating all subsets (the power set):

// For an array of size n, there are 2ⁿ possible subsets.
// Each subset can be represented by a binary number of n bits. Each bit tells you whether to include the corresponding element in the subset.
// For example, if nums = [a, b, c], then:
// 000 (binary) means include nothing: []
// 001 means include only c: [c]
// 010 means include only b: [b]
// 011 means include b and c: [b, c]
// 100 means include only a: [a]
// ...and so on, up to 111 (all included: [a, b, c])

//? How the code works:

// The outer loop goes from 0 to 2ⁿ - 1. Each number represents a subset.
// For each number, the inner loop checks each bit (using if (i & (1 << j))):
// If the j-th bit is set (1), include nums[j] in the current subset.
// This way, all possible combinations are generated.
// This is a very efficient way to generate all subsets using bitwise operations!


