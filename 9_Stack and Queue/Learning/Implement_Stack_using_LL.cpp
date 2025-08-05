//implement stack using linked list
// tc : O(1) for push, pop, top, and size
// sc : O(n) for all operations because we are using a linked list which can grow

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class StackImp
{
private:
    Node* head;
    int stackSize;

public:
    StackImp() : head(nullptr), stackSize(0) {}
    void push(int n)
    {
       if(head == nullptr)
       {
            head = new Node(n);
       }
       else
       {
            Node* newNode = new Node(n);
            newNode->next = head;
            head = newNode;
       }

       stackSize++;
    }

    void pop()
    {
        if(head == nullptr)
        {
            cout << "stack underflow";
            return;
        }

        else{
            Node* temp = head;
            head = head->next;
            delete temp;
            stackSize--;
        }
    }

    int top()
    {
       if(head == nullptr)
       {
            cout << "stack underflow";
            return -1;
       }
       else{
            return head->data;
       }
    }

    int size()
    {
        return stackSize;
    }
};

int main()
{
    StackImp stack;
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.top() << endl; // Should print 20
    cout << "Stack size: " << stack.size() << endl; // Should print 2
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Should print 10
    cout << "Stack size after pop: " << stack.size() << endl; // Should print 1
    return 0;
}