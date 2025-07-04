class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the linked list
        ListNode *prev = nullptr;
        ListNode *current = slow;
        ListNode *nextnode = nullptr;

        while (current != nullptr)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }

        // compare both halves
        ListNode *firstHalf = head;
        ListNode *secondHalf = prev;

        while (secondHalf != nullptr)
        {
            if (firstHalf->val != secondHalf->val)
            {
                return false; // not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};