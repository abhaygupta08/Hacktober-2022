// Q115 https://leetcode.com/problems/maximum-width-of-binary-tree/

// Time: O(N) 
// Space: O(N)  

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root) return ans;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long mmin=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                long long curid=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=curid;
                if(i==size-1) last=curid;
                if(node->left)q.push({node->left,curid*2+1});
                if(node->right)q.push({node->right,curid*2+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
