// Q182 https://www.codingninjas.com/codestudio/problems/1094901?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


// SINGLE ARRAY TABULATION   
// Time: O(N*m)
// Space: O(M)
#include<bits/stdc++.h>
bool wordBreak(vector < string > & dict, int n, string & s) {
    if(n==0) return false;
    vector<bool> dp(s.size()+1,false);
    dp[0]=true;
    for(int i=1;i<=s.size();i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j]){
                string word=s.substr(j,i-j);
                auto it=find(dict.begin(),dict.end(),word);
                if(it!=dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}
