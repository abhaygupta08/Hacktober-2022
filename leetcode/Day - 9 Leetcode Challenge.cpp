/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 
 Given the root of a Binary Search Tree and a target number k, 
 return true if there exist two elements in the BST such that 
 their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
 
 */
class Solution {
    vector<int>res;
    void Inorder(TreeNode* root){
        if(!root) return;
        Inorder(root->left);
        res.push_back(root->val);
        Inorder(root->right);
    }
    // void print(){
    //     for(auto it:res){
    //         cout<<it<<"  ";
    //     }
    //     cout<<endl;
    // }
public:
    bool findTarget(TreeNode* root, int k) {
        Inorder(root);
        // print();
        int s=0;
        int e=res.size()-1;
        while(s<e){
            if(res[s]+res[e]==k){
                return true;
            }
            else if(res[s]+res[e]<k){
                s++;
            }
            else{
                e--;
            }
        }
        return false;
    }
};
