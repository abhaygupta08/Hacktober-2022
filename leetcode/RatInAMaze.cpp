// Q59 https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Time: 4(n*m)
// Space: O(m*n) Auxiliary space by the recursion tree

class Solution{
    public: 
    void recf(int i, int j,vector<vector<int>> &m, int n, vector<string> &ans,string move,vector<vector<int>> &vis,int di[],int dj[]){
        if(i==n-1&&j==n-1){
            ans.push_back(move);
            return;
        }    
        string dir="DLRU";
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];
            if(ni>=0 && nj>=0 && ni<=n-1 && nj<=n-1 && !vis[ni][nj] && m[ni][nj]==1){
                vis[i][j]=1;
                recf(ni,nj,m,n,ans,move+dir[k],vis,di,dj);
                vis[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[]={1,0,0,-1};  //dlru
        int dj[]={0,-1,1,0};
        if(m[0][0]==1)recf(0, 0, m, n, ans,"", vis,di,dj);
        return ans;
    }
};
