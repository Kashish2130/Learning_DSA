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
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
}
