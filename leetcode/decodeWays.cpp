class Solution {
public:
    
    int solve(int i , string &s,vector<int> &dp){
        
        //base case
        if(i>=s.size())
            return 1; //because last digit have only 1 way to decode
        
        else if(s[i]=='0')
            return 0; //because 0 have no letter
        
        else if(i==s.size()-1) 
            return 1;
        
        if(dp[i]!=-1) return dp[i];
        
        else if(s[i]=='1' || (s[i]=='2' &&(s[i+1]>='0' && s[i+1]<='6') )  )
            return dp[i]= solve(i+1,s,dp)+solve(i+2,s,dp);
        else
            return dp[i]= solve(i+1,s,dp);
        
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return solve(0,s,dp);
        
    }
};
