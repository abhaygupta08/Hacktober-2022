//problem statement https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(count==1){
            return NULL;
        }
        temp=head;
        int k=count-n;
        if(k>=1){
            while(--k){
               temp=temp->next;
            }
            temp->next=temp->next->next;
        }else{
            head=head->next;
        }
        return head;
    }
};
