//optimal approach
//tc : o(n)
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0;
    int maxi = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            maxi = max(cnt, maxi);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxi;
}