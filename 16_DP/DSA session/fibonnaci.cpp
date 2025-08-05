class Solution {
public:
    // this is top down approach
    // this is solved by using DP - using hasharray
    //this data storing method is called memorization
    //here if we store from 10-1

    //another approach is - bottom up approach
    //here we store data from 0- 1
    //this storing technique is called tabulation.
    //this approach gives most optimal solution

    int fib(int n, vector<int> map) {
        if (n <= 1) {
            return map[n] = n;
        }

        if (mp.find(n) != mp.end()) {
            return map[n];
        }

        int a = fib(n - 1);
        int b = fib(n - 2);
        map[n] = a + b;
        return map[n];
    }

    int fibo(int n) {
        vector<int> map;
        fib(n, map);

        return;
    }
};