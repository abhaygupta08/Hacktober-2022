// Q106 https://leetcode.com/problems/binary-tree-postorder-traversal/

// Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> s;
        stack<TreeNode*> s2;
        TreeNode* node=root;
        s.push(node);
        while(!s.empty()){ 
            node=s.top();
            s2.push(node);
            s.pop();
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};


//Recursive
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return ans;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};
