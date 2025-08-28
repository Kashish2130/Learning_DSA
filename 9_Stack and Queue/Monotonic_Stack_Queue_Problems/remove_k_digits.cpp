// tc : 0(2n) + o(k)
// sc : 0(n) + 0(n)

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        int n = num.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && k > 0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        if (st.empty())
            return "0";

        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // remove leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0')
        {
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};
