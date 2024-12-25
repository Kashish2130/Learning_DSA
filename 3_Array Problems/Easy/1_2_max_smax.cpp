//these are not working codes 
// here just the approach is written
//optimal way
//TC : O(n)

int largest(vector<int> &arr)
{
    int largest = arr[0];
    for (auto i : arr)
    {
        if (i > largest)
        {
            largest = i;
        }
    }
    return largest;
}

int getSecondLargest(vector<int> &arr)
{
    int max = arr[0];
    int smax = -1;
    for (auto i : arr)
    {
        if (i > max)
        {
            smax = max;
            max = i;
        }
        else if (i < max && i > smax)
        {
            smax = i;
        }
    }
    return smax;
}
