// brute force
// tc : o(n^2)
// sc : o(1)
// ex: [2,2,1,1,1,2,2]

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    int count = 0;
                    count++;
                    if (count > nums.size() / 2)
                    {
                        return nums[i];
                    }
                }
            }
        }
    }
};

// better
// tc : o(n)
// sc : o(n)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            temp[nums[i]]++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            while (temp[i] > n / 2)
            {
                return i;
            }
        }

        return 0;
    }
};

// optimal solution (Boyer-Moore Voting Algorithm)
//  tc : o(n)
//  sc : o(1)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int element = 0;
        int count = 0;

        for (auto i : nums)
        {
            if (count == 0)
            {
                element = i;
            }

            if (i == element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        count = 0;
        for (auto i : nums)
        {
            if (i == element)
            {
                count++;
            }
        }

        if (count > nums.size() / 2)
        {
            return element;
        }

        return 0;
    }
};
