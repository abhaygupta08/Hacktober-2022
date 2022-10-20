// Q123 https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(h)+O(n)+O(h)
// Space: O(n)

bool leaf(TreeNode<int>* node){
    return !node->left&&!node->right;
}
void leftside(TreeNode<int> *root,vector<int> &ans){
    TreeNode<int> *cur=root->left;
    while(cur){
        if(!leaf(cur)) ans.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
    return;
}
void bottomside(TreeNode<int> *root,vector<int> &ans){
    if(leaf(root)) {ans.push_back(root->data); return;}
    if(root->left) bottomside(root->left,ans);
    if(root->right) bottomside(root->right,ans);
}
void rightside(TreeNode<int> *root,vector<int> &ans){
    TreeNode<int> *cur=root->right;
    vector<int> tmp;
    while(cur){
        if(!leaf(cur)) tmp.push_back(cur->data);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
//     ans.insert(ans.end(),tmp.begin(),tmp.end()); (We need right side in the reverse order from down to up)
    for(int i=tmp.size()-1;i>=0;i--){
        ans.push_back(tmp[i]);
    }
    return;
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root) return ans;
    if(!leaf(root)) ans.push_back(root->data);
    leftside(root,ans);
    bottomside(root,ans);
    rightside(root,ans);
    return ans;
}
