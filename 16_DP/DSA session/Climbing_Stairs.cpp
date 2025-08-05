//top-down approach using memoization for climbing stairs problem

class Solution {
public:
    int helper(int n, unordered_map<int, int>& mpp) {
        if (n == 1 || n == 2) {
            return n;
        }

        if (mpp.find(n) != mpp.end()) {
            return mpp[n];
        }

        int a = helper(n - 1, mpp);
        int b = helper(n - 2, mpp);
        mpp[n] = a + b;

        return mpp[n];
    }
    int climbStairs(int n) {

        unordered_map<int, int> mpp;
        return helper(n, mpp);
    }
};