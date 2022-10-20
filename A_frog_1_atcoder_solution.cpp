#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
vector<int>vec(N);
int dp[N];
int ans(int i){
    int cost=INT_MAX;
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    
    cost=min(cost,ans(i-1)+abs(vec[i-1]-vec[i]));
    if(i>1){
    cost=min(cost,ans(i-2)+abs(vec[i]-vec[i-2]));
    }
    
    return dp[i]= cost;
}
int32_t main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
for(int i=0;i<n;i++){
    cin>>vec[i];
}
cout<<ans(n-1);
}