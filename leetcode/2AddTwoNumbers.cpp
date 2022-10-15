/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int Checklen(ListNode *l1)
        {
            ListNode *ptr = l1;
            int len = 0;
            while (ptr != NULL)
            {
                len++;
                ptr = ptr->next;
            }
            return len;
        }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (Checklen(l2) > Checklen(l1))
        {
            swap(l1, l2);
        }
        ListNode *final = l1;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        bool b = 0;
        while (ptr1 != NULL)
        {
            if (ptr2 != NULL)
            {

                int tval = ptr1->val + ptr2->val + b;
                if (tval > 9)
                {
                    b = 1;
                    tval -= 10;
                }
                else
                {
                    b = 0;
                }
                ptr1->val = tval;

                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else
            {
                int tval = ptr1->val + b;
                if (tval > 9)
                {
                    b = 1;
                    tval -= 10;
                }
                else
                {
                    b = 0;
                }
                ptr1->val = tval;

                ptr1 = ptr1->next;
            }
        }
        cout << b;
        if (b)
        {
            ListNode *Node = new ListNode(1);
            ListNode *ptr = l1;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = Node;
            Node->next = NULL;
        }
        return final;
    }
};
