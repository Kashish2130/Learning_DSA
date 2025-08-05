//!STACK FOLLOWS LIFO
// implement stack using array
// tc : O(1) for push, pop, top, and size
// sc : O(1) for all operations because we are using a fixed-size array which becomes its limitation

#include <bits/stdc++.h>
using namespace std;
class StackImp
{
private:
    int topIndex = -1;
    int st[10];

public:
    void push(int n)
    {
        if (topIndex >= 9) // or the size of array minus 1
        {
            cout << "stack overflow";
            return;
        }

        topIndex = topIndex + 1;
        st[topIndex] = n;
    }

    void pop()
    {
        if (topIndex == -1)
        {
            cout << "stack underflow";
            return;
        }

        topIndex = topIndex - 1;
    }

    int top()
    {
        if (topIndex == -1)
        {
            cout << "stack underflow";
            return -1;
        }

        return st[topIndex];
    }

    int size()
    {
        if (topIndex == -1)
        {
            return 0;
        }

        return topIndex + 1;
    }
};

int main()
{
    // Example usage of StackImp class
    StackImp stack;
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.top() << endl; // Should print
    stack.pop();
    cout << "Size of stack: " << stack.size() << endl; // Should print 1
    stack.pop();
    cout << "Size of stack after pop: " << stack.size() << endl; // Should print 0
    stack.pop();                                                 // Should print "stack underflow"
    return 0;
}