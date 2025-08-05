class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(auto ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else if(ch == ')' || ch =='}' || ch ==']')
            {
                if(st.empty()){
                    return false;
                }

                if(ch == ')' && st.top != '(' || 
                ch == '}' && st.top != '{'|| 
                ch == ']' && st.top != '[')
                {
                    return false;
                }

                st.pop();
            }
        }
        return st.empty();
    }
};


give example of valid and invalid strings for testing the isValid function:
// Example of valid strings
// 1. "()" - Valid
// 2. "([])" - Valid
// 3. "{[()]}" - Valid
// 4. "{[()()]}" - Valid
// 5. "((()))" - Valid

// Example of invalid strings
// 1. "(]" - Invalid
// 2. "([)]" - Invalid
// 3. "{[}" - Invalid
// 4. "((())" - Invalid
// 5. "((())]" - Invalid
