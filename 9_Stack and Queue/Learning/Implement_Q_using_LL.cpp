// implement queue using LL

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size = 0;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue()
    {
        Node *temp = front;
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = front->next;
        delete temp;
        size--;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sizeOfQueue()
    {
        cout << "Size of queue: " << size << endl;
    }
};