#include <bits/stdc++.h>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
            return;
        }

        auto top = st.top();
        int min = top.second;

        if (val < min)
        {
            min = val;
        }

        st.push({val, min});
    }

    int top()
    {
        return st.top().first;
    }

    void pop() { st.pop(); }

    int getMin()
    {
        auto top = st.top();
        return top.second;
    }
};

// !Correct Approach:

The pair approach (value, current min) allows you to always know the minimum at each stack level.
Alternatively, you can use two stacks: one for all values, one for the current minimums.

//* but if you use monotonic stack approach, there you are more prone to not support all the stack operations also the data will be lost so that is not the right way!
