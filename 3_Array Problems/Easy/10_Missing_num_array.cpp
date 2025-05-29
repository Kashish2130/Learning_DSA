// brute force
// tc : o(n^2)
// sc:o(1)
//give example array in which a number is missing
// 0,1,2,3,4,6,7,8,9


int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
    return -1;
}

// better - using hashing
// tc : o(n) + o(n)
// sc : o(n) -> not good
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// optimal approach
// using SUM OR XOR
// USING SUM
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s2 += nums[i];
    }

    return (sum - s2);
}

// USING XOR
// TC : o(N)
// sc : o(1)
//tell me if i do xor of 4 and 4 what will be the result?
// 0^1^2^3^4 = 0
// 0^1^3^4 = 2


int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xorResult = 0;
    for (int i = 0; i <= n; i++)
    {
        xorResult ^= i;
    }

    for (int num : nums)
    {
        xorResult ^= num;
    }

    return xorResult;
}

// TC :O(N) ->but better than above
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}
