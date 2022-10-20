/**

/////////////////////////
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 
 //////////////////////////
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* solve(TreeNode* root,int v,int d){
        if(!root) return NULL;
        if(d==2){
            TreeNode* leftnode=new TreeNode(v);
            TreeNode* rightnode=new TreeNode(v);
            leftnode->left=root->left;
            rightnode->right=root->right;
            
            root->left=leftnode;
            root->right=rightnode;
            return root;
        }
        root->left=solve(root->left,v,d-1);
        root->right=solve(root->right,v,d-1);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* n=new TreeNode(val);
            n->left=root;
            return n;
        }
        return solve(root,val,depth);
    }
};
