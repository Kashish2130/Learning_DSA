//? ATOI WITH RECURSION

//tc : O(n) where n is the length of the string based on the number of characters we traverse and number of recursive calls made
//sc : O(1) as we are using constant space for the result and sign
class Solution {
public:
    int helper(string s, int index, int result, int sign) {
        if (index > s.length() || !isdigit(s[index])) {
            return result * sign;
        }

        int digit = s[index] - '0';

        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;

        return helper(s, index + 1, result, sign);
    }

    int myAtoi(string s) {
        // Recursive approach

        int n = s.length();
        int sign = 1;
        int i = 0;

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

        return helper(s, i, 0, sign);
    }
};