#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int wt[N];
int v[N];
int n;
int dp[105][100005];
int ans(int i,int weight){
if(weight==0)return 0;
if(i<0)return 1e15;
if(dp[i][weight]!=-1) return dp[i][weight];
   int k=ans(i-1,weight);
   if(weight-v[i]>=0){
k=min(k, ans(i-1,weight-v[i])+wt[i]);
   }
   return dp[i][weight]=k;

}
int32_t main(){
memset(dp,-1,sizeof(dp));
int w;
cin>>n>>w;
for(int i=0;i<n;i++){
    cin>>wt[i];
    cin>>v[i];
}
int max_val=1e5;
for(int i=max_val;i>=0;i--){
    if(ans(n-1,i)<=w){
        cout<<i<<endl;
        break;
    }
}

}