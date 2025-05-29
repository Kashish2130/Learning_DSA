// Brute force approach
// TC: O(N)+O(X)+O(N-X) = o(2n)
// SC: O(X)
void moveZeroes(vector<int> &nums)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            temp[i] = nums[i];
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }

    for (int i = temp.size(); i < n; i++)
    {
        nums[i] = 0;
    }
}

// Optimal Approach
// TC: O(x)+O(n-x) = O(N)
// SC: no extra space used

void moveZeroes(vector<int> &nums)
{
    int j = 0; // position to place the next non-zero

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

or

void MoveZeroesToEnd(vector<int> &arr)
{
    // 2 pointers approach
    // pointer i Determines the correct position of the nonzero element
    // pointer j will traverse and finds the next nonzero element
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            arr[i] = arr[j];
            i++;
        }
    }
    while (i < arr.size())
    {
        arr[i] = 0;
        i++;    
    }
}
