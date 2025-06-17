//?Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

// brute force solution
// tc: O(n^2)
// sc: O(1)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();
        if (n != goal.length())
            return false;

        for (int i = 0; i < n; i++)
        {
            char temp = s[0]; // Save the first character

            // Shift all characters left
            for (int j = 0; j < n - 1; j++)
            {
                s[j] = s[j + 1];
            }

            s[n - 1] = temp; // Place first char at the end

            if (s == goal)
                return true;
        }

        return false;
    }
};

// optimal solution
// tc: O(n)
// sc: O(n)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        string doubled = s + s;
        return doubled.find(goal) != string::npos; //what npos means: npos is a constant representing the largest possible value for an element of type size_t, which is used to indicate that a substring was not found in the string.
    }
};
