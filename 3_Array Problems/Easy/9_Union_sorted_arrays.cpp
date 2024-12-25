// brute force approach
// TC : O(n1logn) + O(n2logn) + O(n1+n2)
// SC : O(n1+n2) + O(n1+n2)[this is for returning the ans and not storing the array]

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    set<int> st;
    int s1 = a.size();
    int s2 = b.size();
    vector<int> union;
    for (int i = 0; i < s1; i++)
    {
        st.insert(a[i]);
    }

    for (int i = 0; i < s2; i++)
    {
        st.insert(b[i]);
    }

    for (auto i : st)
    {
        union.push_back(i);
    }

    return union;
}

// optimal approach
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int s1 = a.size();
    int s2 = b.size();
    vector<int> unionArr;
    int i = 0;
    int j = 0;
    while (i < s1 && j < s2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < s1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while (j < s2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}