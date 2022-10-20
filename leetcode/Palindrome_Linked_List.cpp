#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *cur = head;

        while (cur)
        {
            v.push_back(cur->val);
            cur = cur->next;
        }
        for (int i = 0; i < v.size() / 2; i++)
            if (v[i] != v[v.size() - 1 - i])
                return false;

        return true;
    }
};