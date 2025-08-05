#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // If operand, add to result
        if (isalnum(ch))
        {
            ans += ch;
        }
        // If '(', push to stack
        else if (ch == '(')
        {
            st.push(ch);
        }
        // If ')', pop and output until '(' is found
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // remove '('
        }
        // If operator
        else
        {
            while (!st.empty() && priority(ch) <= priority(st.top()))
            {
                if (ch == '^' && st.top() == '^')
                    break; // right-associative case for ^
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all remaining operators
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
