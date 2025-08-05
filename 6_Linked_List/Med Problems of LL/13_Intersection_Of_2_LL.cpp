//brute force approach
//tc : O(N+M)
//sc : o(n)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mpp;

        ListNode *temp = headA;

        while (temp != nullptr)
        {
            mpp[temp] = 1;
            temp = temp->next;
        }

        temp = headB;

        while (temp != nullptr)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }
};

//better approach
 //tc : O(N+2M)
//sc : O(1)
class Solution {
public:
    ListNode* collison(ListNode* headA, ListNode* headB, int d) // d stands for difference
    {
        ListNode* temp = headA;
        ListNode* tempb = headB;
        int count = 0;
        while (count != d) {
            count++;
            temp = temp->next;
        }

        while (tempb != nullptr) {
            if (temp == tempb) {
                return temp;
            } else {
                temp = temp->next;
                tempb = tempb->next;
            }
        }

        return nullptr;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int countA=0, countB=0;
        ListNode* temp = headA;
        while (temp != nullptr) {
            countA++;
            temp = temp->next;
        }

        temp = headB;
        while (temp != nullptr) {
            countB++;
            temp = temp->next;
        }

        if (countA > countB) {
            return collison(headA, headB, countA - countB);
        } else {
            return collison(headB, headA, countB - countA);
        }
    }
};

//optimal
//tc : O(N+M)
//sc : O(1)
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if (temp1 == temp2) {
                return temp1;
            }

            if (temp1 == nullptr) {
                temp1 = headB;
            }

            if (temp2 == nullptr) {
                temp2 = headA;
            }
        }

        return temp1;
    }
};