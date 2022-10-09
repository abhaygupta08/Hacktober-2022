// Q142 https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Time: O(n)
Space: O(h)+O(h)  to store i and j stack


class BSTIterator{
private:
    stack<TreeNode*> s;
    bool rev=true;
    void pushAll(TreeNode* root){
        while(root){
            s.push(root);
            if(!rev) root=root->left;
            else root=root->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse){
        rev=isReverse;
        pushAll(root);
    }
    
    bool hasNext(){
            return !s.empty();
        }
    
    int next(){
        TreeNode* t=s.top();
        s.pop();
        if(!rev) pushAll(t->right);
        else pushAll(t->left);
        return t->val;
    }
    
};
class Solution {
    
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(k==i+j) return true;
            if(k>i+j) i=l.next();
            else j=r.next();
        }
        return false;
    }
};





// Time: O(n)
// Space: O(n) 

class Solution {
public:
    bool helper(TreeNode* root,int k,unordered_set <int> &m){
        if(!root) return false;
        if(m.find(k-root->val)!=m.end()) return true;
        m.insert(root->val);
        return helper(root->left,k,m)||helper(root->right,k,m); 
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set <int> m;
        return helper(root,k,m);
    }
};
