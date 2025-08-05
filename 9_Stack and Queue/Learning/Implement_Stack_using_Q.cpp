// tc :// O(n) for push, O(1) for pop and top
// sc : O(n) for storing elements in queue

//! implementing stack using 1 queue

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    queue<int> q;

public:
    void push(int val)
    {
        int s = q.size();
        q.push(val);

        for (int i = 1; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (!q.empty())
        {
            q.pop();
        }
    }

    void top()
    {
        if (!q.empty())
        {
            cout << q.front() << endl;
        }
    }
};


// tc : O(n) for push, O(1) for pop and top
// sc : O(n) for storing elements in stack
//! implement of stack using 2 queue
class StackUsingTwoQueues
{
private:
    queue<int> q1, q2;

public:
    void push(int val)
    {
        q1.push(val);
    }
    void pop()
    {
        if (q1.empty())
            return;

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // Remove the last element which is the top of the stack

        // Swap the queues
        swap(q1, q2);
    }
    void top()
    {
        if (q1.empty())
            return;

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << endl; // The front of q1 is the top of the stack

        // Move the last element to q2
        q2.push(q1.front());
        q1.pop();

        // Swap the queues
        swap(q1, q2);
    }

    bool isEmpty()
    {
        return q1.empty();
    }
    int size()
    {
        return q1.size();
    }
};
