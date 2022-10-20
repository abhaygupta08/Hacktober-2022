// Q143 https://leetcode.com/problems/binary-search-tree-iterator/

// Time: O(1)  pushing n elements and there are n next calls https://youtu.be/D2jMcmxU4bs?t=716
// Space: O(h) 

class BSTIterator {
private:
    stack<TreeNode*> s;
    
    void pushAll(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *t=s.top();
        s.pop();
        // if(t->right) null node can be handled by push all function
        pushAll(t->right);
        return t->val;
    }
    
    bool hasNext() {
        return !s.empty();    
    }
};
