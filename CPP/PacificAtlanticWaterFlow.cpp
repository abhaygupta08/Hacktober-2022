// Q417 https://leetcode.com/problems/pacific-atlantic-water-flow

// Time: O(E+V)
// Space: O(E+V)+O(V)+O(V)

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis)
    {
        if(i<0 || i>=heights.size() || j < 0 || j>=heights[0].size() || vis[i][j] == 1) return;
        vis[i][j] = 1;
        if(i-1>=0 && heights[i-1][j] >= heights[i][j])
            dfs(heights, i-1, j, vis);
        if(i+1<heights.size() && heights[i+1][j] >= heights[i][j])
            dfs(heights, i+1, j, vis);
        if(j-1>=0 && heights[i][j-1] >= heights[i][j])
            dfs(heights, i, j-1, vis);
        if(j+1<heights[0].size() && heights[i][j+1] >= heights[i][j])
            dfs(heights, i, j+1, vis);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> visPac(heights.size(), vector<bool>(heights[0].size(), 0));
        vector<vector<bool>> visAtl(heights.size(), vector<bool>(heights[0].size(), 0));
        for(int i=0; i<heights.size(); i++)
        {
            for(int j=0; j<heights[0].size(); j++)
            {
                if(i == 0 || j == 0)
                {
                    if(visPac[i][j] == 0) dfs(heights, i, j, visPac);
                }
                if(i==heights.size()-1 || j==heights[0].size()-1)
                {                    
                    if(visAtl[i][j] == 0) dfs(heights, i, j, visAtl);
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i<heights.size(); i++)
        {
            for(int j=0; j<heights[0].size(); j++)
            {
                if(visPac[i][j] && visAtl[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};

