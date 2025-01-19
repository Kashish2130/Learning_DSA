//tc : O(log2n)
int lowerBound(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        if (arr[mid] >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//brute force approach
//using normal for loops ->how you can see in striver's sheet
//tc : o(n)
//sc : o(1)

//optimal approach
// tc : o(log n)
// sc : o(1)
int upperBound(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        if (arr[mid] > k) //only this condition is different here
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}


