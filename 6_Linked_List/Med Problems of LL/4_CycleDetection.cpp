//brute force approach
//tc : o(n) * o(1) = o(n) //unordered_map
//or O(n) * 2 * log(n) = O(nlogn) // ordered_map (*2 because looking up and inserting in map both takes log(n) time)

//sc : O(n) * o(1) = O(n)

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        map<ListNode*, int> mpp;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return true;
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

//optimal
//tortoise and hare algorithm
//tc : O(n) 
//sc : O(1)
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};


//* example:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         v
          8 <- 7 <- 6

Step 1:

slow moves to 2
fast moves to 3

Step 2:

slow moves to 3
fast moves to 5

Step 3:

slow moves to 4
fast moves to 7

Step 4:

slow moves to 5
fast moves to 3

Step 5:

slow moves to 6
fast moves to 5

Step 6:

slow moves to 7
fast moves to 7

Now, slow and fast meet at node 7, which means there is a cycle.

// !Key Points:
// slow moves one step at a time.
// fast moves two steps at a time.
// If there is a cycle, fast will eventually catch up to slow inside the cycle.
// If there is no cycle, fast will reach the end (nullptr).
// This is why the algorithm works for cycle detection!