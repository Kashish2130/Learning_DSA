ListNode *removeDup(ListNode *head)
{
    ListNode *curr = head;
    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            ListNode *dup = curr->next;
            curr->next = dup->next;
            if (dup->next)
            {
                dup->next->prev = curr;
            }

            delete dup;
        }
        else
        {
            curr = curr->next
        }
    }

    return head;
}

// 1-1-1-2-3-3-4