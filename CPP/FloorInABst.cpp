// Q138 https://www.codingninjas.com/codestudio/problems/920457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(logn)
// Space: O(1)  

int floorInBST(TreeNode<int> * root, int x){
    int ans=-1;
    while(root){
        if(root->val==x) return x;
        if(x>root->val){ 
            ans=root->val;
            root=root->right;
        }
        else root=root->left;
    }
    return ans;
}
