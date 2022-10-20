//Q29 https://leetcode.com/problems/add-two-numbers/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *d=new ListNode();
        ListNode *t=d;
        int c=0;
        while(l1||l2||c){
            int s=0;
            if(l1){
                s+=l1->val;
                l1=l1->next;
            }
            if(l2){
                s+=l2->val;
                l2=l2->next;
            }
            s+=c;
            c=s/10;
            ListNode * nn=new ListNode(s%10);
            t->next=nn;
            t=t->next;
            
            
        }
        return d->next;

    }

};
