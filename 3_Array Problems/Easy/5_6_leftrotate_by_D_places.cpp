// brute force approach
// TC : O(n)
// SC : O(N)
void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    k = k % size;
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(nums[i]); // storing the first k elements in another vector
    }

    for (int i = k; i < size; i++)
    {
        nums[i - k] = nums[i]; // shifting the elements to the left by k places
    }

    // now putting the elements back from temp to orig array
    // 1st way
    int j = 0;
    for (int i = (size - k); i < k; i++)
    {
        nums[i] = temp[j];
        j++;
    }

    // 2nd way - mathematical way
    // for (int i = (size - k); i < size; i++)
    // {
    //     nums[i] = temp[i - (n - k)];
    // }s
}


// optimal approach
// TC : O(2N)
// SC : O(1)
void rotate(vector<int> &nums, int k)
// array : 1 2 3 4 5 6 7
// assume k = 3
{
    reverse(nums,nums+d); // 1 2 3 -> 3 2 1
    reverse(nums+d,nums+nums.size()); // 4 5 6 7 -> 7 6 5 4
    reverse(nums,nums+nums.size()); // 4 5 6 7 1 2 3 
}
