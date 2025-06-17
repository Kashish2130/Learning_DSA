//?Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

//tc : O(n)
//sc : O(1)

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        vector<int> temp;
        for (auto ch : s) {
            if (ch == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            }

            else if (ch == ')') {
                depth--;
            }
        }

        return maxDepth;
    }
};

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;

        for (char c : s) {
            if (c == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (c == ')') {
                depth--;
            }
        }

        return maxDepth;
    }
};
