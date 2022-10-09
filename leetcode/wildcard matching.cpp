class Solution {
public:
    bool solve(string &str, string &pattern,int i,int j,vector<vector<int>> &dp)
    {
        if(i==0&&j==0)
            return true;
        if(i>0&&j==0)
            return false;
        if(i==0&&j>0)
        {
            for(int k=1;k<=j;k++)
            {
                if(pattern[k-1]!='*')
                   return false;
            }
                   return true;
        }
                   if(dp[i][j]!=-1)
                   return dp[i][j];
                   if(str[i-1]==pattern[j-1]||pattern[j-1]=='?')
                   return dp[i][j]=solve(str,pattern,i-1,j-1,dp);
                   else if(pattern[j-1]=='*')
                   return dp[i][j]=(solve(str,pattern,i-1,j,dp)||solve(str,pattern,i,j-1,dp));
                   else
                                    return false;
                
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,s.length(),p.length(),dp);
    }
};

