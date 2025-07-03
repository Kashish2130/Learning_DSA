//? You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// brute force
// tc : 2n
// sc : O(n)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        int j = 0, k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = (pos[j++]);
            }
            else
            {
                nums[i] = (neg[k++]);
            }
        }
        return nums;
    }
};

// optimal
// tc : O(n)
// sc : O(n)
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n); // Allocate result vector with size n
        int posIndex = 0, negIndex = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                result[posIndex] = nums[i];
                posIndex += 2;
            }
            else
            {
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return result;
    }
};
