// tc: O(n)
// sc: O(1)

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // Cycle detected, now count the length
                int length = 1;
                ListNode *temp = slow->next;
                while (temp != slow)
                {
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }
        return 0; // No cycle
    }
};