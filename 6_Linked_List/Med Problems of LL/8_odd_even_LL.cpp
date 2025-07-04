// brute force
//  tc : O(n^2)
//  sc : O(n)

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        vector<ListNode *> oddNodes;
        vector<ListNode *> evenNodes;

        ListNode *current = head;
        int pos = 1;

        // Step 1: Split nodes into odd and even index lists
        while (current)
        {
            if (pos % 2 == 1)
            {
                oddNodes.push_back(current);
            }
            else
            {
                evenNodes.push_back(current);
            }
            current = current->next;
            pos++;
        }

        // Step 2: Reconnect all odd nodes
        for (int i = 0; i < oddNodes.size() - 1; ++i)
        {
            oddNodes[i]->next = oddNodes[i + 1];
        }

        // Step 3: Reconnect all even nodes
        for (int i = 0; i < evenNodes.size() - 1; ++i)
        {
            evenNodes[i]->next = evenNodes[i + 1];
        }

        // Step 4: Connect end of odd to start of even
        if (!oddNodes.empty())
            oddNodes.back()->next = evenNodes.empty() ? nullptr : evenNodes[0];

        // Step 5: End of even list should point to null
        if (!evenNodes.empty())
            evenNodes.back()->next = nullptr;

        return oddNodes[0];
    }
};

// optimal
//  tc : O(n)
//  sc : O(1)
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head; // handle edge cases
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead; // connect odd list to even list
        return head;
    }
};