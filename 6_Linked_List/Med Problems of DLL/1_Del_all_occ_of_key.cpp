ListNode *deleteallocc(ListNode *head, int key)
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        if (temp->val == key)
        {
            if (temp == head)
            {
                head = head->next;
            }

            ListNode *nextNode = temp->next;
            ListNode *prevNode = temp->prev;

            if (nextNode != nullptr)
            {
                nextNode->prev = prevNode;
            }

            if (prevNode != nullptr)
            {
                prevNode->next = nextNode;
            }

            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}