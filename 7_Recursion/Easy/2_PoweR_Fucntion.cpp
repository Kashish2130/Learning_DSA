//! Recursive approach - Brute Force
//Recursion tree visualization: View images folder no.2 for recursion tree brute force
// Time Complexity: O(n) where n is the exponent
// Space Complexity: O(n) due to the recursive call stack

 class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponents
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }

    double power(double x, long long n) {
        // Base case: anything raised to 0 is 1
        if (n == 0) return 1.0;

        // Recursive case: x^n = x * x^(n-1)
        return x * power(x, n - 1);
    }
};

//* Jaymin's Solution - Recursive Brute Force
double helper(double x, double curr, long long n)
{
    if (n == 0)
        return curr;
    if (n > 0)
        return helper(x, curr * x, n - 1);
    return helper(x, curr / x, n + 1);
}

double myPow(double x, int n)
{
    // convert n to long long to safely handle INT_MIN
    return helper(x, 1.0, (long long)n);
}


//? why do we need to use binary exponentiation?
// The brute force approach has a time complexity of O(n) where n is the exponent.
// This is inefficient for large values of n, as it requires n multiplications.
// Binary exponentiation reduces the time complexity to O(log n) by using the properties of exponents.
// It works by breaking down the exponentiation into smaller parts, allowing us to compute the result more efficiently.
// Binary Exponentiation using Bit Manipulation
// Time Complexity: O(log n) where n is the exponent
// Space Complexity: O(1) as we are using constant space for the result and x


//!  Binary Exponentiation using Iterative Approach
// Time Complexity: O(log n) where n is the exponent
// Space Complexity: O(1) as we are using constant space for the result and x
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n; // use long long to avoid overflow on INT_MIN
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        return result;
    }
};

//? why are using the above while loop?
// we are doing exponentiation by squaring
// this is an efficient way to calculate power
// how it works:
// we can express the power in binary form
// for example, 13 in binary is 1101, which means:
// 13 = 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0
// so we can calculate the power by multiplying the base raised to the power of each bit that is set to 1
// if the bit is 0, we skip that power
// this reduces the number of multiplications needed
// time complexity: O(log n) where n is the exponent
// space complexity: O(1) as we are using constant space for the result and x
// if n is negative, we take the reciprocal of x and make n positive
// we use a loop to iterate through the bits of n
// if the current bit is 1, we multiply the result by x
// we square x for the next bit
// we right shift n by 1 to process the next bit
// this way, we efficiently calculate the power in logarithmic time
// this is known as exponentiation by squaring


//! Binary Exponentiation using Recursive Approach
// tc : O(log n) where n is the exponent
// sc : O(log n) due to the recursive call stack
double powHelper(double x, long long n)
{
    if (n == 0)
        return 1;
    // if power is even
    if (n % 2 == 0)
    {
        // square the base &  halve the exponent
        return powHelper(x * x, n / 2);
    }
    // if power is odd
    else
    {
        // that number * number raise to its power-1
        return x * powHelper(x, n - 1);
    }
}

double myPow(double x, int n)
{
    long long N = n; // use long long to avoid overflow
    if (N < 0)
    {
        // For NEGATIVE power
        x = 1 / x;
        N = -N;
    }
    return powHelper(x, N);
}


//* View images folder no.2 for recursion tree visualization and more understanding of the recursive approach

