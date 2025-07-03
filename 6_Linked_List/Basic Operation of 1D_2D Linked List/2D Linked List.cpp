#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    //! INSERTION
    void insertAtStart(int val)
    {
        Node *newnode = new Node(val);
        if (head != nullptr)
        {
            newnode->next = head;
            head->prev = newnode;
        }
        head = newnode;
    }

    void insertAtEnd(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    void insertAtPos(int val, int pos)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node *temp = head;
        int count = 0;
        while (temp != nullptr && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
        {
            cout << "pos not found";
            return;
        }

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = newnode;
        }

        temp->next = newnode;
    }

    //! DELETION

    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "empty list";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "empty list";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPos(int pos)
    {
        if (head == nullptr)
        {
            cout << "nothing to delete";
            return;
        }

        if (pos == 0)
        {
            deleteAtStart();
            return;
        }

        Node *temp = head;

        int count = 0;
        while (temp != nullptr && count < pos)
        {
            temp = temp->next;
            count++;
        }

        if (!temp)
        {
            cout << "invalid pos";
            return;
        }

        temp->prev->next = temp->next;
        if (temp->next)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    //! REVERSING A DLL

    //* we can also use stack to reverse a linked list
    //first take all the ele of LL in stack and then pop and again fill it in the list
    //The LL will be reversed.
    //But that is inefficient.
    void reverse()
    {
        if (!head || !head->next)
        {
            // Empty list or only one node — no need to reverse
            return;
        }

        Node *current = head;
        Node *temp = nullptr;

        // Swap prev and next for all nodes
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // move to "next" node in original direction
        }

        // After loop, temp is at previous node — the new head
        if (temp != nullptr)
            head = temp->prev;
    }
};

int main()
{
    LinkedList list;

    return 0;
}