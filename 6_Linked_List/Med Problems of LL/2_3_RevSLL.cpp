// iterative
//! refer jenny's video for explanation!
//https://www.youtube.com/watch?v=Tk_fi5l8cag
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextnode = nullptr;
        while (current != nullptr)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        return prev;
    }
};

// recursive
//! striver's video

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // base case: if head is null or only one node
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
};