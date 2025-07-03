//! Normal way to count good numbers
//tc: O(log n) for exponentiation
//sc: O(1) for the iterative approach
//This is an iterative approach using [exponentiation by squaring.]
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long helper(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenPossibilities = helper(5, even, MOD);
        long long oddPossibilities = helper(4, odd, MOD);

        return (evenPossibilities * oddPossibilities) % MOD;
    }
};


//recursive approach
//tc: O(log n) for exponentiation
//sc: O(log n) for the recursive call stack
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, int mod) {
        if (exp == 0) return 1;
        if (exp % 2 == 0) {
            long long half = modPow(base, exp / 2, mod);
            return (half * half) % mod;
        } else {
            return (base * modPow(base, exp - 1, mod)) % mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenWays = modPow(5, even, MOD);
        long long oddWays = modPow(4, odd, MOD);

        return (evenWays * oddWays) % MOD;
    }
};

//why are we doing mod everywhere?
//In competitive programming, we often deal with large numbers that can exceed the limits of standard data types.
//To prevent overflow and ensure results fit within the constraints, we use modulo operations.
//The modulo operation helps keep numbers manageable and within the range of standard data types.
//In this case, we use a large prime number (1e9 + 7)
//as the modulus to ensure that our results remain within a reasonable range while still being unique.
//This is particularly important in problems involving combinatorial counts or large calculations,
//where results can grow exponentially.
