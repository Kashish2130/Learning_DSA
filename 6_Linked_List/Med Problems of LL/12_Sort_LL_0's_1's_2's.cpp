class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        // Create three dummy heads for 0s, 1s, and 2s
        ListNode zeroDummy(0), oneDummy(0), twoDummy(0);
        ListNode *zero = &zeroDummy, *one = &oneDummy, *two = &twoDummy;
        ListNode* curr = head;
        while (curr) {
            if (curr->val == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->val == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        // Connect the three lists
        zero->next = oneDummy.next ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr;
        return zeroDummy.next;
    }
};