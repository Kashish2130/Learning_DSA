// burte force solution
// tc : O(n^2)
// sc : O(1)

class Solution
{
public:
    int sumSubnumsayMins(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        int mod = (int)(1e9 + 7);
        for (int i = 0; i < n; i++)
        {
            int minVal = nums[i];
            int maxVal = nums[i];
            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                int diff = maxVal - minVal;
                if (diff < 0)
                    diff = 0; // Ensure non-negative difference
                sum = (sum + diff) % mod;
            }
        }
        return sum;
    }
};

// optimal
//tc : O(n)
//sc : O(n)

class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        vector<int> nse;
        stack<int> st;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse.push_back(n);
            } else {
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(), nse.end());
        return nse;
    }

    vector<int> psee(vector<int>& arr) {
        vector<int> psee;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                psee.push_back(-1);
            } else {
                psee.push_back(st.top());
            }
            st.push(i);
        }
        return psee;
    }

    vector<int> nge(vector<int>& arr) {
        vector<int> nge;
        stack<int> st;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge.push_back(n);
            } else {
                nge.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nge.begin(), nge.end());
        return nge;
    }

    vector<int> pgee(vector<int>& arr) {
        vector<int> pgee;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                pgee.push_back(-1);
            } else {
                pgee.push_back(st.top());
            }
            st.push(i);
        }
        return pgee;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long Minsum = 0, Maxsum = 0;
        int n = nums.size();

        vector<int> nextSmaller = nse(nums);
        vector<int> prevSmaller = psee(nums);
        vector<int> nextGreater = nge(nums);
        vector<int> prevGreater = pgee(nums);

        for (int i = 0; i < n; i++) {
            long long right = nextSmaller[i] - i;
            long long left = i - prevSmaller[i];
            Minsum += left * right * 1LL * nums[i];
        }

        for (int i = 0; i < n; i++) {
            long long right = nextGreater[i] - i;
            long long left = i - prevGreater[i];
            Maxsum += left * right * 1LL * nums[i];
        }
        return Maxsum - Minsum;
    }
};


