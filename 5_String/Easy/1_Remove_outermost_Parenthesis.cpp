class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result;
        int depth = 0; //to keep the count of opening and closing parentheses
        // Iterate through each character in the string
        // if the character is '(', increment depth, if it is ')', decrement depth
        // if depth is greater than 0, append the character to the result
        // this way we skip the outermost parentheses
        //! Time complexity: O(n), where n is the length of the string
        //! Space complexity: O(n), for the result string

        for (char c : s)
        {
            if (c == '(')
            {
                if (depth > 0)
                    result += c; // not outermost
                depth++;
            }
            else
            {
                depth--;
                if (depth > 0)
                    result += c; // not outermost
            }
        }

        return result;
    }
};
