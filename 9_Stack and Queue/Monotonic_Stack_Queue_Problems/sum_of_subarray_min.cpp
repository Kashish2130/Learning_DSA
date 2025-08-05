// brute force
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long sum = 0;
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++)
        {
            int minVal = arr[i];
            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, arr[j]);

                sum = (sum + minVal) % mod;
            }
        }
        return sum;
    }
};

class Solution
{
public:
    vector<int> nse(vector<int> &arr)
    {
        vector<int> nse;
        stack<int> st;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                nse.push_back(n);
            }
            else
            {
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(), nse.end());
        return nse;
    }

    vector<int> psee(vector<int> &arr)
    {
        vector<int> psee;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                psee.push_back(-1);
            }
            else
            {
                psee.push_back(st.top());
            }
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        long long sum = 0;
        int mod = (int)(1e9 + 7);
        int n = arr.size();
        vector<int> nextSmaller = nse(arr);
        vector<int> prevSmaller = psee(arr);
        for (int i = 0; i < n; i++)
        {
            long long right = nextSmaller[i] - i;
            long long left = i - prevSmaller[i];
            sum = (sum + (right * left * arr[i]) % mod) % mod;
        }
        return sum;
    }
};


//to find sum of subarray maximum
//we can use the same logic with next greater and previous greater elements
//just replace the min with max in the code above

🔁 Summary Table : 
Component           Time Space
    nse()           O(n) O(n)
    psee()          O(n) O(n)
    Final Sum Loop  O(n) O(1)
    Total           O(n) O(n)

// tc : o(n)
// sc : o(n)