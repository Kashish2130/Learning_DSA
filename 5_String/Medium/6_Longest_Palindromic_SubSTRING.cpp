//? Given a string s, return the longest palindromic substring in s.

// burte force
// tc : O(n^3)
// sc : O(1)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxi = 0;
        string result;

        for (int i = 0; i < n; i++)
        {
            string substring = "";
            for (int j = i; j < n; j++)
            {
                substring += s[j];
                string temp = substring;
                reverse(temp.begin(), temp.end());
                if (substring == temp && substring.length() > maxi)
                {
                    maxi = substring.length();
                    result = substring;
                }
            }
        }

        return result;
    }
};

// Is there any better solution?
//  Yes, we can use the expand around center technique to find the longest palindromic substring in O(n^2) time complexity.
// tc : O(n^2)
// sc : O(1)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, maxLen = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            // Odd-length palindrome
            expandAroundCenter(s, i, i, start, maxLen);
            // Even-length palindrome
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLen)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > maxLen)
            {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

//! what does this function do? [expamdAroundCenter]
//  It expands around the center to find the length of the palindrome.
// what expand around center means?
//  It means to consider each character (or pair of characters) as the center of a potential palindrome and expand outwards to check for palindromic properties.
//  This method is efficient because it only requires a single pass through the string for each center, leading to O(n^2) time complexity in total.
//  The function takes two indices, left and right, which represent the current center of the palindrome.

//  It checks for both odd and even length palindromes by expanding around the center.

// It returns the length of the palindrome found by expanding around the center.



//optimal solution
Time: O(n)
But: complex and rarely asked in interviews. Not necessary unless you're aiming for super-competitive coding rounds.
//!"Manacher’s Algorithm is a linear-time solution to find the longest palindromic substring. It works by transforming the input to handle even/odd lengths uniformly and uses a concept of mirroring to avoid redundant computation. While it's very efficient with O(n) time, it's rarely asked due to its complexity. Most practical solutions use expand-around-center with O(n²) time."

