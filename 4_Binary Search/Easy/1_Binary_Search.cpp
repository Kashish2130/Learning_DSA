//tc : o(log2n)

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// recursive approach
int function(nums, low, high, target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }
    elseif(target > nums[mid])
    {
        return function(nums, mid + 1, high, target)
    }
    else
    {
        return function(nums, mid - 1, high, target)
    }
}

int search(vector<int> &nums, int target)
{
    return function(nums, 0, nums.size() - 1, target); //calling the above function
}