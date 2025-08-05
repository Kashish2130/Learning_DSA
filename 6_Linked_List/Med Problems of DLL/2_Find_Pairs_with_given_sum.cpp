// brute force approach
// tc : o(n^2)
// sc : o(1) //pairs vector is only taken for showing the output and not for computation.
vector<pair<int, int>> findpairs(ListNode *head, int k)
{
    vector<pair<int, int>> pairs;
    ListNode *temp = head;
    while (temp)
    {
        ListNode *temp2 = temp->next;
        while (temp2)
        {
            if (temp->val + temp2->val == k)
            {
                pairs.push_back({temp->val, temp2->val});
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return pairs;
}

// optimal
//tc : o(n)
//sc : o(1)
vector<pair<int, int>> findpairs(ListNode *head, int k)
{
    vector<pair<int, int>> pairs;
    ListNode *left = head;
    ListNode *right = head;

    while (right->next != nullptr)
    {
        right = right->next;
    }

    while (left != right && left != nullptr && right != nullptr && left->prev != right)
    {
        if (left->val + right->val == k)
        {
            pairs.push_back({left->val, right->val});
            left = left->next;
            right = right->prev;
        }

        if (left->val + right->val > k)
        {
            right = right->prev;
        }
        else
        {
            left = left->next;
        }
    }
    return pairs;
}
