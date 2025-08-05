
// brute force

// tc : n^3
// sc : o(n) //acc to below n - size of nums1 array
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int n = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n; i++)
        {
            int key = nums1[i];
            bool found = false;
            for (int j = 0; j < n2; j++)
            {
                found = false;
                if (nums2[j] == key)
                {
                    for (int k = j + 1; k < n2; k++)
                    {
                        if (nums2[k] > key)
                        {
                            ans.push_back(nums2[k]);
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        ans.push_back(-1);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// optimal
// tc : n + m
// sc : n + m

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> ans;
        int n = nums2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }

            
        }

        int m = nums1.size();
        for (int i = 0; i < m; i++)
        {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};


