// brute force
//   tc : O(2*len)
//   sc : O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int count = 0;
        // Count total nodes
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        // If we need to remove the head node
        if (n == count)
        {
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        temp = head;
        // Move to the node just before the one to delete
        for (int i = 1; i < count - n; ++i)
        {
            temp = temp->next;
        }
        ListNode *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;
    }
};

// optimal approach
//    tc : O(len)
//    sc : O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        // Move fast n steps ahead
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        // If fast is nullptr, we need to remove the head
        if (!fast)
        {
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        // Move both pointers until fast->next reaches the end
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // Delete the nth node from end
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return head;
    }
};