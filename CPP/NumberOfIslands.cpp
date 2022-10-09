// Q161 https://leetcode.com/problems/number-of-islands/

// Time: O(E+V)  //not confirmed
// Space: O(E+V)+O(V)+O(V)  


class Solution {
    void dfs(int i, int j, vector<vector<char>>& g){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()) return;
        if(g[i][j]=='0') return;
        g[i][j]='0';
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i+1,j,g);
        dfs(i,j-1,g);
        
    }
public:
    int numIslands(vector<vector<char>>& g) {
        int n=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='1'){
                    dfs(i,j,g);
                    n++;
                }
            }
        }
        return n;
    }
};
