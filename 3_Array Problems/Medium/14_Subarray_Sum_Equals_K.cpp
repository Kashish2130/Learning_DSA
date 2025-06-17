// brute force approach
// tc : o(n^3)
// sc : O(1)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, sum;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }

                if (sum == k)
                {
                    count++;
                }
            }
        }

        return count;
    }
};


// better approach
// tc : O(n^2)
// sc : O(1)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0, sum;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }

        return count;
    }
};


// optimal approach
// tc : o(n)
// sc :
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int prefixSum = 0, count = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // To handle the case where a subarray starts from index 0
        for (int num : nums)
        {
            prefixSum += num;
            int remove = prefixSum - k;
            count += prefixSumCount[remove]; // Check how many times the prefix sum that would make the current sum equal to k has occurred
            prefixSumCount[prefixSum]++;     // Increment the count of the current prefix sum
        }
        return count;
    }
};
 