class Solution
{
public:
    vector<int> preGreaterEle(vector<int> &nums)
    {
        stack<int> st;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }

            st.push(nums[i]);
        }

        return ans;
    }
};


