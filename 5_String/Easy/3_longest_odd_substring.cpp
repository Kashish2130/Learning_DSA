//? You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.

// brute force
//tc : O(n^2)
// sc : O(n^2) since we are storing all the odd substrings in a vector

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        vector<string> oddStrings;

        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = i; j < n; j++)
            {
                temp += num[j];
                if ((temp.back() - '0') % 2 !=
                    0)
                { // Check if last digit is odd
                    oddStrings.push_back(temp);
                }
            }
        }

        string maxOdd = "";
        for (int i = 0; i < oddStrings.size(); i++)
        {
            if (oddStrings[i].length() > maxOdd.length() ||
                (oddStrings[i].length() == maxOdd.length() &&
                 oddStrings[i] > maxOdd))
            {
                maxOdd = oddStrings[i];
            }
        }

        return maxOdd;
    }
};

// optimal solution
//tc : O(n)
// sc : O(1) since we are not using any extra space except for the output string
class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};


// if ((num[i] - '0') % 2 != 0) {
//! explanation of above line
// but can we divide a string by 2
//  dont we have to use stoi() to convert it to an integer?
//  yes, but we are not dividing, we are checking if the last digit is odd
//  if the last digit is odd, then we can return the substring from 0 to i
//  ok so if we are not dividing then we can just check if the last digit is odd without converting to an integer
//  so we can just return the substring from 0 to i
