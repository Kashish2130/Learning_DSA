//sort stack using temporary stack
//tc : O(n^2) 
//sc  :O(n)

#include <iostream> 
#include <stack>
using namespace std;
void sortStack(stack<int>& input) {
    stack<int> tempStack;

    while(!input.empty())
    {
        int top = input.top();
        input.pop();

        while(!tempStack.empty() && tempStack.top() > top)
        {
            input.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(top);
    }

    // Transfer sorted elements back to input stack
    while(!tempStack.empty())
    {
        input.push(tempStack.top());
        tempStack.pop();
    }
}


#include <bits/stdc++.h>
using namespace std;

// ITERATIVE VERSION USING TEMPSTACK
// TC : O(N^2)
// SC : O(N)
void sortStack(stack<int> &s)
{
    stack<int> tempstack;

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();

        while (!tempstack.empty() && tempstack.top() > temp)
        {
            s.push(tempstack.top());
            tempstack.pop();
        }

        tempstack.push(temp);
    }

    while (!tempstack.empty())
    {
        s.push(tempstack.top());
        tempstack.pop();
    }
}

// RECURSIVE VERSION
// TC : O(N^2)
// SC : O(N)
// Helper: Inserts element in sorted order
void insertSorted(stack<int> &s, int element)
{
    if (s.empty() || s.top() <= element)
    {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    insertSorted(s, element);
    s.push(top);
}

// Main recursive sort function
void sortStack(stack<int> &s)
{
    if (!s.empty())
    {
        int top = s.top();
        s.pop();
        sortStack(s);         // Sort remaining stack
        insertSorted(s, top); // Insert element in sorted order
    }
}