//? Leaders in an array
//A leader is the one element which is greater than all the elements on its right.
//Last element is always a leader.


#include <vector>
using namespace std;

// Brute force approach
// Time complexity: O(n^2)
// Space complexity: O(n) //result vector

class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader)
                result.push_back(nums[i]);
        }
        return result;
    }
};

// optimal
//  Time complexity: O(n)
//  Space complexity: O(n)

class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> result;
        int max = INT_MIN;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                result.push_back(max);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
