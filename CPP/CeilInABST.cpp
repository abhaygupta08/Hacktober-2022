// Q139 https://www.codingninjas.com/codestudio/problems/920464?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(logn)
// Space: O(1)  


int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil=-1;
    while(root){
        if(root->data==x) return x;
        if(root->data>x){
            ceil=root->data;
            root=root->left;
        }
        else root=root->right;
    }
    return ceil;
}
