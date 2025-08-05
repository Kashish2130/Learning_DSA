// tc : o(2n)
// sc : o(n)

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            if (i < n) //
            {
                if (st.empty())
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(st.top());
                }
            }
            st.push(nums[i % n]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//! things to notice or remember or understand

//* 🔁 Why use i % n?
// You're looping from 2n - 1 down to 0 — which is twice the size of the array.

// But nums only has n elements, so we do:
// nums[i % n]
// This helps us treat the array as circular.

//* ❓ Why if (i < n) condition?
// You're looping twice, but you only want to store answers once — for the original elements (not the extra circular ones).

// So:
// if (i < n)

// means:
// ➡️ “We’re now on the first pass of the original array (i = n-1 to 0), so now save the answer.”

// 🔄 The first half (i = 2n-1 to n)
// Used only to fill the stack with values from the end (simulate circular behavior).

// No answer is added to ans.

// 🧮 The second half (i = n-1 to 0)
// This is the actual array, so now we add the result (st.top() or -1) to ans.