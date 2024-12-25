//this is not proper codde 
//this is just for reference

bool sorted_not(vector<int> &nums)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}