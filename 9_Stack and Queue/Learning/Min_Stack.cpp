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
