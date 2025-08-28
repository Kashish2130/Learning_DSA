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
            while (!st.empty() && arr[st.top()] > arr[i]) // here we are storing indexes of the psee and hence arr[st.top()] > arr[i]
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
            st.push(i); // here we are storing indexes of the arr and hence st.push(i);
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

/// give me dry run on an array : 3,2,7
// to find sum of subarray minimums
// we find next smaller and previous smaller elements

// next smaller elements for 3,2,7 are 2,7,-1
// previous smaller elements for 3,2,7 are -1,-1,2
// so for each element we calculate the contribution to the sum
// for 3: right = 2 - 0 = 2, left = 0 - (-1) = 1
// contribution = 3 * 2 * 1 = 6 
// for 2: right = 7 - 1 = 6, left = 1 - (-1) = 2
// contribution = 2 * 6 * 2 = 24
// for 7: right = -1 - 2 = -3, left = 2 - 2 = 0
// contribution = 7 * (-3) * 0 = 0
// so the total sum = 6 + 24 + 0 = 30
// so the final answer is 30
// !Correct Approach:
// The pair approach (value, current min) allows you to always know the minimum at each stack level.
// Alternatively, you can use two stacks: one for all values, one for the current minimums.
// but if you use monotonic stack approach, there you are more prone to not support all the stack operations also the data will be lost so that is not the right way!
// !Correct Approach:
// to find sum of subarray minimums
// we can use the same logic with next smaller and previous smaller elements
// just replace the min with max in the code above



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