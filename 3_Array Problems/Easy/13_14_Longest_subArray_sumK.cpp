// brute force
// tc : o(n^2)
// sc : o(1)
int lenOfLongestSubarr(vector<int> &arr, int k)
{
    int len = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// better ->  for(positives)
// optimal -> for(positives & negatives)
// this solution would work for both positives and negatives
// tc : o(n logn) -> ordered map
// tc : o(n *1) -> unordered map
// sc : o(n) -> for worst case if each index has individual prefixSUM
int lenOfLongestSubarr(vector<int> &arr, int k)
{
    map<int, int> prefixSumMap; // Map to store prefix sums
    int maxLen = 0;             // Maximum length of subarray
    int sum = 0;                // Running prefix sum

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // Case 1: checking if the sum is equal to k
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: we are checking if the remaining sum exists in the map or not
        int rem = sum - k;
        if (prefixSumMap.find(rem) != prefixSumMap.end())
        {
            maxLen = max(maxLen, i - prefixSumMap[rem]);
        }

        // Case 3: here we are checking if the sum already exists in the map or not.
        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }
    }

    return maxLen;
}
// optimal -> for(positives)
// tc : o(n^2)
// sc :
int lenOfLongestSubarr(vector<int> &arr, int k)
{
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += a[right];
        }
    }
    return maxLen;
}