// Q178 https://www.codingninjas.com/codestudio/problems/630471?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Recursion
// Time: >O(2^n), Exponential
// Space: O(n) 
#include<bits/stdc++.h>
int f(int ind, int tar,int * a){
        if(ind==0){
            return (tar%a[0]==0);
        }
        int nt=f(ind-1,tar,a);
        int t=0;
        if(a[ind]<=tar)
            t=f(ind,tar-a[ind],a);
        return t+nt;
 }

long countWaysToMakeChange(int *a, int n, int tar)
{
     return f(n-1,tar,a);
}

// Memorisation
// Time: O(N*m)
// Space: O(N*M)+O(N) = auxiliary stack space+ dp
#include<bits/stdc++.h>
long f(int ind, int tar,int * a,vector<vector<long>> &dp){
        if(ind==0){
            return (tar%a[0]==0);
        }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
        long nt=f(ind-1,tar,a,dp);
        long t=0;
        if(a[ind]<=tar)
            t=f(ind,tar-a[ind],a,dp);
        return dp[ind][tar]=t+nt;
 }

long countWaysToMakeChange(int *a, int n, int tar)
{
    vector<vector<long>> dp(n,vector<long>(tar+1,-1));
     return f(n-1,tar,a,dp);
}

// DP
// Time: O(N*m)
// Space: O(N*M)
#include<bits/stdc++.h>

long countWaysToMakeChange(int *a, int n, int val)
{
    vector<vector<long>> dp(n,vector<long>(val+1,0));
    for(int j=0;j<val+1;j++) dp[0][j]=val%a[0]==0;
    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=val;tar++){
            long nt=dp[ind-1][tar];
            long t=0;
            if(a[ind]<=tar)
                t=dp[ind][tar-a[ind]];
            dp[ind][tar]=t+nt;
        }
    }
     return dp[n-1][val];
}

// TABULATION
// Time: O(N*m)
// Space: O(2*M)
#include<bits/stdc++.h>

long countWaysToMakeChange(int *a, int n, int val)
{
    vector<long> p(val+1,0),c(val+1,0);
    for(int j=0;j<val+1;j++) p[j]=val%a[0]==0;
    for(int ind=1;ind<n;ind++){
        for(int tar=0;tar<=val;tar++){
            long nt=p[tar];
            long t=0;
            if(a[ind]<=tar)
                t=c[tar-a[ind]];
            c[tar]=t+nt;
        }
        p=c;
    }
     return p[val];
}

