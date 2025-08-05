//iterative approach
// tc : o(3n)
// sc : O(1)
class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head)
    {
        head = reverse(head);
        ListNode *curr = head;
        int carry = 1;
        ListNode *prev = nullptr;
        while (curr && carry)
        {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr->next;
        }
        if (carry)
        {
            prev->next = new ListNode(carry);
        }
        return reverse(head);
    }
};


//recursive approach
//tc : O(n)
//sc : o(n)
class Solution
{
public:
    int helper(ListNode *temp)
    {
        int carry;
        carry = helper(temp->next);
        temp->val += carry;
        if (temp->val < 10)
        {
            return 0;
        }
        else
        {
            carry = temp->val / 10;
            temp->val = temp->val % 10;
            return carry;
        }
    }

    ListNode *addOne(ListNode *head)
    {
        int carry;
        carry = helper(head);
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            newNode->next = head;
            return newNode; // If carry is still present, create a new node
        }
        return head; // If no carry, return the modified list
    }
};
