class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int i=n-1;i>=0;i--){ 
            //initialization
         for(int j=m-1;j>=0;j--){
                if(i==n-1&&j==m-1) // fill last row 
                {dp[i][j]=grid[i][j];
               
                }
               else if(i==n-1){    // fill last row
                   dp[i][j]=grid[i][j]+dp[i][j+1];
               }
               else if(j==m-1){    // fill last column
                   dp[i][j]=grid[i][j]+dp[i+1][j];
               }
               else{
                // fill remaning row of cell
                    dp[i][j]=grid[i][j]+min(dp[i][j+1],dp[i+1][j]);
               }
            }
        }
            return dp[0][0];
    }
};