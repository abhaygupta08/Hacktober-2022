// Q130 https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(n)
// Space: O(h)

void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL) return;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    
    if(child>root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    
    if(root->left||root->right) root->data=tot;
}  
