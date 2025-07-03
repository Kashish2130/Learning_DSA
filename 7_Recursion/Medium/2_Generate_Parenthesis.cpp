//? generate diff combination of valid and balanced parenthesis on the basis of input.

class Solution
{
public:
    void backtrack(int open, int close, int n, string current, vector<string> &result)
    {
        if (current.size() == n * 2)
        {
            result.push_back(current);
            return;
        }

        // if (close > open)
        // {
        //     return;
        // }

        if (open > 0)
        {
            backtrack(open - 1, close, n, current + "(", result);
        }

        if (close > open)
        {
            backtrack(open, close - 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(n, n, n, "", result);
        return result;
    }
};

//? TIME COMPLEXITY

//! The code generates all possible valid combinations of parentheses for a given number n. For example, if n = 3, it finds all ways to arrange 3 opening and 3 closing brackets so that they are always balanced.The time complexity is O(4ⁿ / √n) because:

//* The number of valid combinations grows very fast as n increases.
//* This number is given by the Catalan number, which is about 4ⁿ divided by the square root of n.
//* The code checks every possible valid way, so it takes time proportional to the number of valid answers.

//! In short: The code is efficient for small n, but the number of answers grows very quickly as n gets bigger!

//? SPACE COMPLEXITY

//! The space complexity of this solution is also O(4ⁿ / √n).

//Explanation:

//* All valid combinations are stored in the result vector. The number of valid combinations is the nth Catalan number, which is about 4ⁿ / (n√n).
//* Each combination is a string of length 2n.
//* So, the total space used is proportional to the number of valid combinations times their length, but the dominant factor is the number of combinations: O(4ⁿ / √n).
//* There is also extra space used by the recursion stack, which can go up to O(n) deep, but this is much smaller than the space for storing all results.