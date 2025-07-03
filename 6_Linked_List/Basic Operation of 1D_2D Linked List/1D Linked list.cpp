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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    //! TRAVERSAL
    void printList()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++; //* length of linked list
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    //! SEARCH
    bool searchByValue(int val)
    {
        if (head == nullptr)
        {
            return false;
        }

        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //! INSERTION
    void insertAtStart(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = head;
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
    }

    void insertAtPos(int val, int pos)
    {
        Node *newnode = new Node(val);
        if (pos <= 1 || head == nullptr)
        {
            newnode->next = head;
            head = newnode;
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
            cout << "Position out of range\n";
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    //! DELETION
    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "cant delete";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "cant delete";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPos(int pos)
    {
        if (head == nullptr)
        {
            cout << "cant";
            return;
        }

        if (pos == 0)
        {
            deleteAtStart();
            return;
        }

        Node *temp = head;
        int count = 0;
        while (temp != nullptr && count < pos - 1)
        {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "pos not found";
            return;
        }

        temp->next = temp->next->next;
        delete temp->next;
    }

    void deleteByValue(int val)
    {
        if (head == nullptr)
        {
            cout << "cant delete";
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != val)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "val not found";
            return;
        }

        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
};

int main()
{
    LinkedList list;
    list.insertAtEnd(2);
    return 0;
}