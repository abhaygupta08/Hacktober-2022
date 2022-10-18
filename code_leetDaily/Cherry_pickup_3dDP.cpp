#include <bits/stdc++.h> 

int maxPick(int i,int j1,int j2,int r,int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if( j1<0 || j2<0 || j1>=c || j2>=c)
           return -1e9;
    if(i==r-1)
    {
        if(j1==j2)
            return grid[i][j1];
        else
            return (grid[i][j1] + grid[i][j2]);
    }
    if(dp[i][j1][j2] != -1)
         return dp[i][j1][j2];
    
    int maxi = -1e9;
    for(int dj1=-1;dj1<=1;dj1++)
    {
       for(int dj2=-1;dj2<=1;dj2++)
       {
           int value=0;
           if(j1==j2)
               value=grid[i][j1];
           else
               value= grid[i][j1]+grid[i][j2];
           
           value+=maxPick(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
           maxi=max(maxi,value);
       }
        
    }
    return dp[i][j1][j2]=maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
     vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int>(c,-1)));

   // return maxPick(0,0,c-1,r,c,grid,dp);
    
    for(int j1=0;j1<c;j1++)  // base case;
    {
        for(int j2=0;j2<c;j2++)
        {
            if(j1==j2) dp[r-1][j1][j2]=grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1]+grid[r-1][j2];
        }
    }
    
    for(int i=r-2;i>=0;i--)
    {
        for(int j1=0;j1<c;j1++)
        {
            for(int j2=0;j2<c;j2++)
            {
               int maxi = -1e9;
                for(int dj1=-1;dj1<=1;dj1++)
                {
                   for(int dj2=-1;dj2<=1;dj2++)
                   {
                       int value=0;
                       if(j1==j2)
                           value=grid[i][j1];
                       else
                           value= grid[i][j1]+grid[i][j2];
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c)
                           value+=dp[i+1][j1+dj1][j2+dj2];
                       else
                           value = value + -1e9;
                       
                       maxi=max(maxi,value);
                   }  
                }   
                dp[i][j1][j2]=maxi;
            }
        }
    }
      return dp[0][0][c-1];  
}
