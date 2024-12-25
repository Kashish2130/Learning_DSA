// brute force approach
// TC : O(N1*N1)
// SC :O(N2)

vector<int> findIntersection(vector<int> &a, vector<int> &b)
{
    vector<int> inter;
    int s1 = a.size();
    int s2 = b.size();
    if (s1 > s2)
    {
        int vis[s2] = {0};
    }
    else
    {
        int vis[s1] = {0};
    }

    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if (a[i] == b[j] && vis[j] == 0)
            {
                inter.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if (b[j] > a[i])
            {
                break;
            }
        }
    }
    return inter;
}

// optimal approach
// TC : O(N1+N2) -> worst case if no match is found
// SC : O(1) ->no extra space used
vector<int> findIntersection(vector<int> &a, vector<int> &b)
{
    vector<int> inter;
    int s1 = a.size();
    int s2 = b.size();
    int i = 0;
    int j = 0;

    while (i < s1 && j < s2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            inter.push_back(a[i]);
            i++;
            j++;
        }
    }

    return inter;
}