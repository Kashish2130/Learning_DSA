//Brute force
//tc : o(n)
//sc : O(1)
// simpler to use but two pass
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;
        temp = head;

        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }
};

//optimal
//tc : o(n)
//sc : o(1)

//single pass
//* fast and slow pointers
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        
        while(fast! = nullptr && fast->next!= nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

