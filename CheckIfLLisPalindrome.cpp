// Q 34 https://leetcode.com/problems/palindrome-linked-list/submissions/


// Time: (find mid) + (rev half) + (match other half with first) + (again find the mid) + (again change LL to original by rev the 2nd half (if asked in interview))
// O(n/2)+O(n/2)+O(n/2)+O(n/2)+O(n/2)
class Solution {
public:
    ListNode* rev(ListNode* rh){
        ListNode *nh=NULL;
        while(rh){
            ListNode *n=rh->next;
            rh->next=nh;
            nh=rh;
            rh=n;
        }
        return nh;
    }
    
    bool isPalindrome(ListNode* h) {
        if(!h||!h->next) return true;
        ListNode *s=h,*f=h;
        while(f->next&&f->next->next){
            s=s->next;
            f=f->next->next;
        }
        s->next=rev(s->next);
        ListNode *t=h;
        s=s->next;
        while(s){
            if(s->val!=t->val) return false;
            s=s->next;
            t=t->next;
        }
        return true;
    }
};
