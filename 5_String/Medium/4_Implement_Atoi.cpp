//?Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

//tc: O(n), where n is the length of the string s.
// sc: O(1), since we are using a constant amount of space.

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1;
        int i = 0;
        long long ans = 0; // Use long long to handle overflow

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Convert digits to integer
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign == 1 && ans > INT_MAX) {
                return INT_MAX; // Overflow for positive numbers
            }
            if (sign == -1 && ans > (long long)INT_MAX + 1) {
                return INT_MIN; // Overflow for negative numbers
            }
            i++;
        }

        return (int)(ans * sign);
    }
};