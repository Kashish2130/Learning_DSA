#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int priority(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPrefix(string s) {
    // Reverse the infix expression and swap '(' with ')'
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (isalnum(ch)) {
            ans += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else {
            while (!st.empty() && priority(ch) < priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            // For right-associative '^'
            if (!st.empty() && ch == '^' && st.top() == '^') {
                // do nothing, just push
            } else {
                while (!st.empty() && priority(ch) == priority(st.top()) && ch != '^') {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}