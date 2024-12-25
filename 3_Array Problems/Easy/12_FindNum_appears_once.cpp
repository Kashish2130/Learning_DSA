// brute force
// tc :o(n^2)
// sc :o(1)
int singleNumber(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return nums[i];
        }
    }
}

// better- using hash arrays
// tc : o(n) + o(n) + o(n) = o(3n)
// sc : o(maxi) ->max can vary
int singleNumber(vector<int> &nums)
{
    int maxi;
    for (auto i : nums)
    {
        maxi = max(maxi, i);
    }

    vector<int> hash(maxi + 1, 0);

    for (auto i : nums)
    {
        hash[i]++;
    }

    for (int i = 1; i < hash.size(); i++)
    {
        if (hash[i] == 1)
        {
            return i;
        }
    } // here it will access the index of hash

    // for (auto i : nums) {
    //     if (hash[i] == 1) {
    //         return i;
    //     }
    // } //here it will access the ele in nums

    return -1;
}

// better - using ordered maps
// tc :o(nlogm) + o(n/2 +1)
// sc :o(n/2+1)
int singleNumber(vector<int> &nums)
{
    map<long long, int> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp[nums[i]]++;
    }

    for (auto pair : temp)
    {
        if (pair.second == 1)
        {
            return pair.first;
        }
    }

    return -1;
}

// optimal
// tc :o(n)
// sc :o(1)
int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (auto i : nums)
    {
        result ^= i;
    }

    return result;
}