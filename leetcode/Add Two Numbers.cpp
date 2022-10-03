//problem statement https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* t1=l1,*t2=l2;
        ListNode* st=new ListNode(0);
        ListNode* st1=st;
        while(t1&&t2){
            int a=t1->val+t2->val+c;
                c=a/10;
            ListNode*newNode=new ListNode(a%10);
            newNode->next=NULL;
            st1->next=newNode;
            t1=t1->next;
            t2=t2->next;
            st1=st1->next;
        }
        while(t1){
            int a=t1->val+c;
                c=a/10;
            ListNode*newNode=new ListNode(a%10);
            newNode->next=NULL;
            st1->next=newNode;
            t1=t1->next;
            st1=st1->next;
        }
        while(t2){
            int a=t2->val+c;
                c=a/10;
            ListNode*newNode=new ListNode(a%10);
            newNode->next=NULL;
            st1->next=newNode;
            t2=t2->next;
            st1=st1->next;
        }
        if(c>0){
            ListNode*newNode=new ListNode(c);
            newNode->next=NULL;
            st1->next=newNode;
            st1=st1->next;
        }
        return st->next;
    }
};
