// Q146 https://www.codingninjas.com/codestudio/problems/893106?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=3

// Time: O(n)  
// Space: O(n) 

void helper(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &h,BinaryTreeNode<int>* &p){
    if(!root) return;
    helper(root->left,h,p);
    if(p==NULL) h=root;
    else{
        root->left=p;
        p->right=root;
    }
    p=root;
    helper(root->right,h,p);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* h=NULL,*p=NULL;
    helper(root, h,p);
    return h;
}
