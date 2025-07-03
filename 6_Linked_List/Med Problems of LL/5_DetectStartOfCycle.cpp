// brute force approach
// tc : o(n) * o(1) = o(n) //unordered_map
// or O(n) * 2 * log(n) = O(nlogn) // ordered_map (*2 because looking up and inserting in map both takes log(n) time)

// sc : O(n) * o(1) = O(n)

class Solution
{
public:
    bool detectCycle(ListNode *head)
    {
        map<ListNode *, int> mpp;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            else
            {
                mpp[temp] = 1;
                temp = temp->next;
            }
        }

        return false;
    }
};

// optimal
// tortoise and hare algorithm
// tc : O(n)
// sc : O(1)
class Solution
{
public:
    ListNode* detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head; // Reset slow to head for cycle length calculation
                while (slow != fast) 
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Return the node where the cycle starts
            }
        }
        return nullptr;
    }
};
