class Solution {
public:
   int solve(int index,int buy,vector<int>& prices,int limit,vector<vector<vector<int>>> &dp)
    {
        if(index==prices.size())
            return 0;
        if(limit==0)
            return 0;
        if(dp[index][buy][limit]!=-1)
            return dp[index][buy][limit];
        int profit=0;
        if(buy)
        {
            int buyKaro=-prices[index]+solve(index+1,0,prices,limit,dp);
            int skipKaro=0+solve(index+1,1,prices,limit,dp);
            profit=max(buyKaro,skipKaro);
        }
        else
        {
            
            int sellKaro=prices[index]+solve(index+1,1,prices,limit-1,dp);
            int skipKaro=0+solve(index+1,0,prices,limit,dp);
            profit=max(sellKaro,skipKaro);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,prices,k,dp);
    }
};
