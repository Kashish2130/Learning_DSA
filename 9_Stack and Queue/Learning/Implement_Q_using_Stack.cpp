//tc : O(n) for push, O(1) for pop and top
//sc : O(n) for storing elements in queue

//! implementing queue using 2 stack

#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val)
    {
        s1.push(val);
    }

    void pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty())
        {
            s2.pop(); 
        }
    }

    void top()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty())
        {
            cout << s2.top() << endl;
        }
    }
};

